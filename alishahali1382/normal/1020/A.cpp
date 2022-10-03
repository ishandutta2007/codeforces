#include <bits/stdc++.h>

using namespace std;

long long n, h, a, b, k, ans, ta, fa, tb, fb;

int main(){
	cin>>n>>h>>a>>b>>k;
	
	for (int i=0; i<k; i++){
		cin>>ta>>fa>>tb>>fb;
		ans=abs(ta-tb);
		if (ta==tb){
			ans=abs(fa-fb);
		}
		else if (fa>b){
			ans+=fa-b+abs(fb-b);
		}
		else if (fa<a){
			ans+=a-fa+abs(fb-a);
		}
		else{
			ans+=abs(fa-fb);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}