#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n),b(n);
		long long s=0,ss=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			s+=a[i];
			ss+=a[i]*a[i];
		}
		for(int i=0;i<n;i++){
			cin >> b[i];
			s+=b[i];
			ss+=b[i]*b[i];
		}
		vector<int> dp1(10005),dp2(10005);
		dp1[a[0]]=1;
		dp1[b[0]]=1;
		for(int i=1;i<n;i++){
			fill(dp2.begin(),dp2.end(),0);
			for(int j=1;j<=10000;j++){
				if(dp1[j]==1){
					dp2[j+a[i]]=1;
					dp2[j+b[i]]=1;
				}
			}
			dp1=dp2;
		}
		long long m=-100000;
		for(int i=1;i<=10000;i++){
			if(dp1[i]){
				if(abs(i-s/2)<abs(m-s/2)){
					m=i;
				}
			}
		}
		cout << m*m+(s-m)*(s-m)+(n-2)*ss << "\n";
	}
	return 0;
}