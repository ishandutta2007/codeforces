#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    int ct=0;
    while(t--){
        int n;
        cin >> n;
        ct++;
        vector<int> v(n);
        vector<int> cnt(n+2);
        int x,y;
        cin >> x >> y;
        y-=x;
        vector<vector<int> > pos(n+2);
        for(int i=0;i<n;i++){
            cin >> v[i];
            cnt[v[i]]++;
            pos[v[i]].push_back(i);
        }
        vector<int> ans(n);
        int maxx=0,no=0;
        int c=n-x;
        p_q<pair<int,int> > pq;
        vector<int> cc(n+2);
        for(int i=1;i<=n+1;i++){
            if(cnt[i]==0){
                no=i;
            }
            else{
                pq.push({cnt[i],i});
                cc[cnt[i]]++;
                maxx=max(maxx,cnt[i]);
            }
        }
        auto del=[&](int a){
            cc[cnt[a]]--;
            if(cnt[a]==maxx && cc[cnt[a]]==0){
                maxx--;
            }
            cnt[a]--;
            cc[cnt[a]]++;
        };
        while(x--){
            auto h=pq.top();
            pq.pop();
            del(h.sc);
            auto l=pos[h.sc].back();
            ans[l]=h.sc;
            pos[h.sc].pop_back();
            pq.push({h.fs-1,h.sc});
        }
        if(y>2*(c-maxx)){
            cout << "NO\n";
            continue;
        }
        if(2*maxx<c){
            p_q<pair<int,int> > poz;
            for(int i=1;i<=n+1;i++){
                if(cnt[i]){
                    poz.push({cnt[i],i});
                }
            }
            while(y--){
                c--;
                auto a=pq.top();
                pq.pop();
                auto b=poz.top();
                poz.pop();
                if(a.sc==b.sc){
                    auto d=b;
                    b=poz.top();
                    poz.pop();
                    poz.push(d);
                }
                if(pos[b.sc].size()==0){
                    poz.push(b);
                    b=poz.top();
                    assert(pos[b.sc].size());
                    ans[pos[b.sc].back()]=a.sc;
                    for(int i=0;i<n;i++){
                        if(ans[i]!=a.sc && v[i]!=a.sc && ans[i]!=v[i]){
                            swap(ans[pos[b.sc].back()],ans[i]);
                            break;
                        }
                    }
                    break;
                }
                ans[pos[b.sc].back()]=a.sc;
                del(a.sc);
                pq.push({a.fs-1,a.sc});
                pos[b.sc].pop_back();
                poz.push({b.fs-1,b.sc});
            }
        }
        else{
            vector<pair<int,int> > z;
            while(pq.size()){
                auto h=pq.top();
                pq.pop();
                for(auto k:pos[h.sc]){
                    z.push_back({h.sc,k});
                }
            }
            auto r=z;
            reverse(r.begin(),r.end());
            for(int i=0;i<r.size();i++){
                if(y==0){
                    break;
                }
                if(r[i].fs!=z[i].fs){
                    y--;
                    ans[z[i].sc]=r[i].fs;
                }
            }
        }
        cout << "YES\n";
        for(int i=0;i<n;i++){
            if(ans[i]==0){
                cout << no << " ";
            }
            else{
                cout << ans[i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}