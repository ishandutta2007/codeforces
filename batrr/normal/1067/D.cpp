#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9, LOG = 35;
const ll INF = 1e18;
struct Matrix{
	vector< vector< double > > val;
	int n, m;
	Metrix(){
		val.clear();
	}
	Matrix(int _n, int _m){
		n = _n;
		m = _m;
		val.resize(n, vector< double > (m, 0));
	}
	Matrix operator *(Matrix b){
		int nn = n, mm = b.m;
		if(m != b.n){
			cerr << "matrix mult";
			assert(0);
		}
		Matrix res(nn, mm);
		for(int i = 0; i < nn; i++)
			for(int j = 0; j < mm; j++)
				for(int q = 0; q < m; q++)
					res.val[i][j] += val[i][q]* b.val[q][j];
		return res;
	}
};
struct line{
	double k, b;	
	bool operator < (line a){
		return k < a.k || (k == a.k && b  < a.b);
	}
	double cross(line a){
		return -(b - a.b) / (k - a.k);
	}
};
struct convex_hull{
	vector< line > v;
	vector< double > vc;
	void add(line l){
		while(!v.empty() && v.back().k == l.k)
			v.pop_back();
		while(v.size() > 2){
			line a = v[v.size() - 2];
			line b = v[v.size() - 1];
			if(l.cross(a) > l.cross(b))
				v.pop_back();	
			else
				break;
		}
		v.pb(l);
	}
	void calc(){
		vc.clear();
		for(int i = 0; i + 1 < v.size(); i++)
			vc.pb(v[i].cross(v[i + 1]));
		vc.pb(1e18);
	}             
	double get_val(double x){
		int id = lower_bound(vc.begin(), vc.end(), x) - vc.begin();
		return v[id].k * x + v[id].b;
	}
    double get_id(double x){
		int id = lower_bound(vc.begin(), vc.end(), x) - vc.begin();
		return id;
	}
};
vector< line > vline;
convex_hull C;
int n;
ll T, t;
double M, ans, dp;
int main(){
	scanf("%d%lld", &n, &T);
	for(int i = 0; i < n; i++){
		int a, b;
		double p;
		scanf("%d%d%lf", &a, &b, &p);
		M = max(M, b * p);
		vline.pb({p, p * a});
	}
	sort(vline.begin(), vline.end());
	for(auto it : vline)
		C.add(it);
	C.calc();
	/*
	for(ll t = 0; t < T; t++){
		cerr << t << ":" << C.get_id(t * M - dp) << endl;
		dp = dp + C.get_val(t * M - dp);
	} 
	cerr << dp << endl;
	*/
	t = 0;
	n = C.v.size();
	dp = 0;
	for(int i = 0; i < n; i++){
		if(C.get_id(t * M - dp) != i)
			continue; 
		vector< Matrix > kp(LOG, Matrix(3, 3));  
		kp[0].val[0][0] = (1 - C.v[i].k); 
		kp[0].val[0][1] = C.v[i].k * M; 
		kp[0].val[0][2] = C.v[i].b; 
		kp[0].val[1][1] = kp[0].val[1][2] = kp[0].val[2][2] = 1;
		for(int i = 1; i < LOG; i++)
			kp[i] = kp[i - 1] * kp[i - 1];      
		
		Matrix mt(3, 1);
		mt.val[0][0] = dp;
		mt.val[1][0] = t;
		mt.val[2][0] = 1;

		for(int j = LOG - 1; j >= 0; j--){
			Matrix nxtmt = kp[j] * mt;
			double nxtdp = nxtmt.val[0][0];
			ll nxtt = t + (1ll<<j);
			if(C.get_id(nxtt * M - nxtdp) != min(i, n - 1) || nxtt >= T)
				continue;        
			/*
			cerr << j << " " << t << endl;  
			cerr << nxtmt.val[0][0] << endl;
			cerr << nxtmt.val[1][0] << endl;
			cerr << nxtmt.val[2][0] << endl;
			*/
			mt = nxtmt;
			dp = nxtdp;
			t = nxtt;
		}
		dp = dp + C.get_val(t * M - dp); 
		t++;
		if(t == T)
			break;	            
	}
	ans = dp;
	printf("%.10f", ans);
	return 0;
}