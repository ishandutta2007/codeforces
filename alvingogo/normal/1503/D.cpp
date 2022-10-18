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
    vector<int> v(2*n),vis(2*n);
    vector<int> fr(2*n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if((a<n) xor (b<n) xor 1){
            cout << -1 << "\n";
            return 0;
        }
        fr[a]=1;
        fr[b]=0;
        v[a]=b;
        v[b]=a;
    }
    int bg=2*n,sm=-1,bb=2*n,ss=-1,s1=-1,s2=-1,b1=2*n,b2=2*n;
    auto put=[&](int i,int t){
        if(i<n){
            if(t==1){
                s1=max(s1,i);
            }
            else{
                s2=max(s2,i);
            }
        }
        else{
            if(t==1){
                b1=min(b1,i);
            }
            else{
                b2=min(b2,i);
            }
        }
    };
    auto get=[&](int i,int t){
        //cout << i << " " << t << "\n";
        int z1=max(i,v[i]),z2=min(i,v[i]);
        bg=min(bg,z1);
        sm=max(sm,z2);
        vis[i]=vis[v[i]]=1;
        if(t==1){
            put(i,1);
            put(v[i],2);
        }
        else{
            put(i,2);
            put(v[i],1);
        }
    };
    int ans=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            continue;
        }
        int nw=0,cnt=0;
        nw+=fr[i];
        cnt++;
        get(i,1);
        while(ss<sm || bb>bg){
            if(ss<sm){
                ss++;
                if(vis[ss]){
                    continue;
                }
                if(b1>ss && ss>s1 && b2>v[ss] && v[ss]>s2){
                    nw+=fr[ss];
                    get(ss,1);
                    cnt++;
                }
                else if(b2>ss && ss>s2 && b1>v[ss] && v[ss]>s1){
                    nw+=fr[v[ss]];
                    cnt++;
                    get(ss,2);
                }
                else{
                    //cout << b1 << " " << s1 << " " << b2 << " " << s2 << " " << ss << " " << v[ss] << "\n";
                    cout << "-1" << "\n";
                    return 0;
                }
            }
            else if(bb>bg){
                bb--;
                if(vis[bb]){
                    continue;
                }
                if(b1>bb && bb>s1 && b2>v[bb] && v[bb]>s2){
                    nw+=fr[bb];
                    cnt++;
                    get(bb,1);
                }
                else if(b2>bb && bb>s2 && b1>v[bb] && v[bb]>s1){
                    nw+=fr[v[bb]];
                    cnt++;
                    get(bb,2);
                }
                else{
                    //cout << b1 << " " << s1 << " " << b2 << " " << s2 << " " << bb << " " << v[bb] << "\n";
                    cout << "-1" << "\n";
                    return 0;
                }
            }
        }
        //cout << cnt << " " << nw << "\n";
        ans+=min(nw,cnt-nw);
    }
    cout << ans << "\n";
    return 0;
}