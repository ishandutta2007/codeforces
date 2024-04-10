#include <bits/stdc++.h>
using namespace :: std;

typedef long long ll;

int n;
string s;
vector<ll> v;
vector<ll> done[5000000];

typedef complex<double> base;

void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(int i=0; i<n/2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}

	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 1;
	while(n < max(v.size(), w.size())) n <<= 1;
	n <<= 1;
	fv.resize(n);
	fw.resize(n);
	fft(fv, 0);
	fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}

vector<ll> red(vector<ll> v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] >= 1000) {
			if (i+1 == v.size()) {
				v.push_back(0);
			}
			v[i+1] += v[i]/1000;
			v[i] %= 1000;
		}
	}

	while (v.back() == 0)
		v.pop_back();
	return v;
}

vector<ll> multy(vector<ll> v, int k) {
	for (int i = 0; i < v.size(); ++i)
		v[i] *= k;
	return red(v);
}


bool compare(vector<ll> a, vector<ll> b) {
	a = red(a);
	b = red(b);
	if (a.size() > b.size())
		return 1;
	if (a.size() < b.size())
		return 0;
	for (int i = (int)a.size()-1; i >= 0; --i) {
		if (a[i] < b[i])
			return 0;
		if (a[i] > b[i])
			return 1;
	}
	return 1;
}


vector<ll> powe(int k) {
	if (done[k].size() != 0)
		return done[k];
	vector<ll> v;
	if (k == 0) {
		v.push_back(1);
		done[k] = v;
		return v;
	}

	if (k%2 == 1) {
		v = multy(powe(k-1), 3);
		done[k] = v;
		return v;
	}

	v = powe(k/2);
	v = red(multiply(v, v));
	done[k] = v;
	return v;
}

vector<ll> comp(int y) {
	vector<ll> v;
	if (y <= 2) {
		v.push_back(y);
		return v;
	}

	if (y%3 == 0) {
		v = powe(y/3);
		return v;
	}

	if (y%3 == 2) {
		v = multy(powe(y/3), 2);
		return v;
	}

	if (y%3 == 1) {
		v = multy(powe((y-4)/3), 4);
		return v;
	}
}

bool chk(int y) {
	return compare(comp(y), v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
	while (s.length()%3 != 0)
		s = "0" + s;
	n = s.length();
	for (int i = 0; i < n/3; ++i) {
		v.push_back(100*(s[3*i]-'0')+10*(s[3*i+1]-'0')+(s[3*i+2]-'0'));
	}

	reverse(v.begin(), v.end());
	v = red(v);

	int expo = 3*(v.size()-1);
	int last = v.back();
	int bound = max(1, 3*(int)((log(last)+expo*log(10))/(log(3)))-3);
	while (true) {
		if (chk(bound)) {
			cout << bound << endl;
			return 0;
		}
		bound++;
	}
}