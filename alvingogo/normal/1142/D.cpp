#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct no{
	int a[11][11]={0};
};
int main(){
	AquA;
	string s;
	cin >> s;
	int n=s.length();
	vector<no> v(n);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(i){
			int y=s[i-1]-'0';
			for(int j=y+1;j<11;j++){
				for(int k=0;k<11;k++){
					if((s[i]-'0')<k){
						int cnt=0;
						for(int l=(j+1)%11;l!=k;l=(l+1)%11){
							cnt+=l;
						}
						v[i].a[k][(k+j-y+s[i]-'0'+cnt)%11]+=v[i-1].a[j][k];
						ans+=v[i-1].a[j][k];
					}
				}
			}
		}
		if(s[i]-'0'){
			v[i].a[10][s[i]-'0']++;
			ans++;
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<11;j++){
			for(int k=0;k<11;k++){
				if(v[i].a[j][k]){
					cout << i << " " << j << " " << k << " " << v[i].a[j][k] << endl;
				}
			}
		}
	}
	*/
	cout << ans << "\n";
	return 0;
}