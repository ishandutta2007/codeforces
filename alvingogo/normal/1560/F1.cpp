#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
using namespace std;

int calk(string s){
	int a[10]={0};
	int l=s.length();
	int k=0;
	for(int i=0;i<l;i++){
		if(a[s[i]-'0']==0){
			a[s[i]-'0']=1;
			k++;
		}
	}
	return k;
}
int ch(string s){
	int a=0;
	for(int i=0;i<s.length();i++){
		a*=10;
		a+=s[i]-'0';
	}
	return a;
}
int main(){
	fastio;
	int t;
	cin >> t;
	
	while(t--){
		string s;
		int k;
		cin >> s >> k;
		int a=ch(s);
		int l=s.length();
		int b[10]={0};
		
		int ans=1099999999,z=0;
		string x=s;
		
		for(int i=0;i<l;i++){
			//cout << i << endl;
			if(s[i]!='9'){
				//cout << i << x << endl;
				x[i]=s[i]+1;
				int p=0;
				if(b[x[i]-'0']!=1){
					b[x[i]-'0']=1;
					p=1;
				} 
				
				//cout << x << endl;
				for(int j=i+1;j<l;j++){
					x[j]='0';
				}
				//cout << x << endl;
				if(calk(x)<=k){
					if(ans>ch(x)-a && ch(x)-a>=0){
						ans=ch(x)-a;
						z=ch(x);
					}
				}
				//cout << x << endl;
				for(int j=0;j<10;j++){
					if(b[j]==1){
						for(int g=i+1;g<l;g++){
							x[g]=j+'0';
						}
						if(calk(x)<=k){
							if(ans>ch(x)-a && ch(x)-a>=0){
								ans=ch(x)-a;
								z=ch(x);
							}
						}
						break;
					}
				}
				//cout << x << endl;
				if(calk(x)<=k){
					if(ans>ch(x)-a && ch(x)-a>=0){
						ans=ch(x)-a;
						z=ch(x);
					}
				}
				if(p){
					b[x[i]-'0']=0;
				}
			}
			//cout << i << endl;
			x[i]=s[i];
			b[x[i]-'0']=1;
			/*for(int f=0;f<10;f++){
				cout << b[f] << " ";
			}
			cout << endl;*/
			if(i!=l-1){
				for(int j=s[i+1]-'0'+1;j<10;j++){
					//cout << j << endl;
					if(b[j]==1){
						x[i+1]=j+'0';
						//cout << x << endl;
						for(int p=0;p<10;p++){
							if(b[p]==1){
								for(int g=i+2;g<l;g++){
									x[g]=p+'0';
								}
								break;
							}
						}
						//cout << x << endl;
						//cout << ch(x) << endl;
						if(calk(x)<=k){
							if(ans>ch(x)-a && ch(x)-a>=0){
								ans=ch(x)-a;
								z=ch(x);
								//cout << ans << z << endl;
							}
						}
						//cout << x << endl;
						break;
					}
				}
			}	
			if(calk(x)<=k){
				if(ans>ch(x)-a && ch(x)-a>=0){
					ans=ch(x)-a;
					z=ch(x);
				}
			}
			
		}
		cout << z << endl;
	}
	return 0;
}