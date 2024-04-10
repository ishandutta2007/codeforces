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
        vector<long long> v(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        if(v[0]*(n-1)+(sum-v[0])>0 || v[n-1]*(n-1)+(sum-v[n-1])<0){
            cout << "INF\n";
            continue;
        }
        long long l=-1e6-5,r=-l;
        auto calc=[&](long long x){
            long long bg=-1,sm=1,s1=0,s2=0;
            for(int i=0;i<n;i++){
                long long c=v[i]+x;
                if(c>=0){
                    s1+=c;
                    bg=max(bg,c);
                }
                else{
                    s2+=c;
                    sm=min(sm,c);
                }
            }
            if(bg<0){
                return (v[n-1]+x)*(s2-(v[n-1]+x))-x*x*(n-1);
            }
            else if(sm>0){
                return (v[0]+x)*(s1-(v[0]+x))-x*x*(n-1);
            }
            else{
                return bg*s2+sm*s1-bg*sm-x*x*(n-1);
            }
        };
        while(r>l+2){
            //cout << l << " " << r << " ";
            long long lr=l+(r-l)/3,rl=l+2*(r-l)/3;
            if(calc(lr)>calc(rl)){
                r=rl;
            }
            else{
                l=lr;
            }
            //cout << lr << " " << rl << " " << calc(lr) << " " << calc(rl) << "\n";
        }
        //cout << l << "\n";
        cout << max(max(calc(l),calc(r)),max(calc(l+1),calc(r-1))) << "\n";
    }
	return 0;
}