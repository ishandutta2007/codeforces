#include <bits/stdc++.h>
#define PB push_back

using namespace std;


const int maxn = 2e5 + 100;
int v[maxn];
vector <int> s;

int main(){
	int n;
	cin >> n;
	long double sum = 0, num = 1;
	s.push_back(0);
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		if (t == 1){
			int a, k;
			cin >> a >> k;
			v[a - 1] += k;
			sum += a * k;
		}
		if (t == 2){
			int a;
			cin >> a;
			s.push_back(a);
			num ++;
			sum += a;
		}
		if (t == 3){
			int k = s.size() - 1;
			if (k > 0){
				sum -= s[k];
				v[k - 1] += v[k];
				sum -= v[k];
				v[k] = 0;
				s.pop_back();
				num --;
			}
		}
		cout << fixed << setprecision(6) << sum / num << endl;
	}
}