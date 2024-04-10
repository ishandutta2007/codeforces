#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n;
	cin >> n;
    vector<int> c(n),d(n);
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    for(int i=0;i<n;i++){
        cin >> d[i];
    }
	vector<int> a(n),b(n);
	long long ans=0;
    int z=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]=c[i]-a[i];
        z+=a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
		b[i]=d[i]-b[i];
        z+=b[i];
	}
    if(z){
        cout << -1 << "\n";
        return 0;
    }
	int e=0,f=0;
	for(int i=0;i<n;i++){
		e+=a[i];
		f+=b[i];
		if(e>0 && f<0){
			int y=min(abs(e),abs(f));
			e-=y;
			f+=y;
			ans+=y;
		}
		else if(f>0 && e<0){
			int y=min(abs(e),abs(f));
			e+=y;
			f-=y;
			ans+=y;
		}
		ans+=abs(e);
		ans+=abs(f);
	}
	cout << ans << "\n";
    return 0;
}