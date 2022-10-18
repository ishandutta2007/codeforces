#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

int main(){
	fastio;
	int n,k;
	cin >> n;
	k=n;
	vector<int> qs(n+1,1),cs(n+1,0),dd(n+1,0);
	int rr=n;
	while(rr>1 && k>1){
		cout << "?";
		qs[rr]++;
		for(int i=1;i<=n;i++){
			cout << " " << qs[i];
		}
		cout << endl;
		int mt;
		cin >> mt;
		if(mt!=0){
			dd[mt]=qs[rr]-1;
		}
		else{
			int p=k-qs[rr]+2;
			k=p-1;
			cs[rr]=p;
			qs[rr]=n;
			for(int i=1;i<=n;i++){
				if(dd[i]!=0){
					cs[i]=dd[i]+p;
					dd[i]=0;
					qs[i]=n;
				}
			}
			for(;rr>0;rr--){
				if(cs[rr]==0){
					break;
				}
			}
		}
		if(qs[rr]==n){
			int p=1;
			cs[rr]=p;
			for(int i=1;i<=n;i++){
				if(dd[i]!=0){
					cs[i]=dd[i]+p;
					dd[i]=0;
					qs[i]=n;
				}
			}
			break;
		}
	}
	if(k==1){
		cs[rr]=1;
	}
	cout << "!";
	for(int i=1;i<=n;i++){
		cout << " " << cs[i];
	}
	cout << endl;
	return 0;
}