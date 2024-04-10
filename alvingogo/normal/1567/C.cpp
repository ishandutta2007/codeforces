#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int l=s.length();
		vector<int> x(l);
		for(int i=0;i<l;i++){
			x[i]=s[i]-'0';
		}
		vector<int> y(l);
		int z=0;
		for(int i=0;i<(1<<l);i+=4){
			int p=1;
			for(int j=0;j<l-2;j++){
				y[j]=i&(1<<(l-j-1));
				if(y[j]>0){
					y[j]=1;
				}
				//cout << y[j] << endl;
				if(y[j]==1){
					x[j+2]+=10;
				}
			}
			for(int j=0;j<l;j++){
				if(x[j]-y[j]>18 || x[j]-y[j]<0){
					//cout << j << x[j] << y[j] << endl;
					p=0;
				}
				else{
					p*=min(x[j]-y[j]+1,19-x[j]+y[j]);
				}
			}
			for(int j=0;j<l-2;j++){
				if(y[j]==1){
					x[j+2]-=10;
				}
			}
			z+=p;
		}
		z-=2;
		cout << z << "\n";
	}
	return 0;
}