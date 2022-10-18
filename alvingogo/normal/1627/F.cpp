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
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<vector<int> > ver(k+1,vector<int>(k+1)),hor(k+1,vector<int>(k+1));
        for(int i=0;i<n;i++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            a--;
            b--;
            c--;
            d--;
            if(a+b+c+d>2*k-2){
                a=k-a-1;
                b=k-b-1;
                c=k-c-1;
                d=k-d-1;
            }
            if(a==c){
                if(b<d){
                    swap(b,d);
                }
                hor[a][b]++;
                hor[k-a-1][k-b]++;
            }
            else{
                if(a<c){
                    swap(a,c);
                }
                ver[a][b]++;
                ver[k-a][k-b-1]++;
            }
        }
        vector<vector<int> > dis(k+1,vector<int>(k+1,1e9));
        dis[k/2][k/2]=0;
        p_q<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
        pq.push({0,{k/2,k/2}});
        while(pq.size()){
            auto h=pq.top();
            pq.pop();
            if(dis[h.sc.fs][h.sc.sc]!=h.fs){
                continue;
            }
            pair<int,int> z={h.sc.fs-1,h.sc.sc},u=min(z,h.sc);
            if(z.fs>=0 && dis[z.fs][z.sc]>h.fs+hor[u.fs][u.sc]){
                dis[z.fs][z.sc]=h.fs+hor[u.fs][u.sc];
                pq.push({dis[z.fs][z.sc],z});
            }
            z={h.sc.fs+1,h.sc.sc};
            u=min(z,h.sc);
            if(z.fs<=k && dis[z.fs][z.sc]>h.fs+hor[u.fs][u.sc]){
                dis[z.fs][z.sc]=h.fs+hor[u.fs][u.sc];
                pq.push({dis[z.fs][z.sc],z});
            }
            z={h.sc.fs,h.sc.sc-1};
            u=min(z,h.sc);
            if(z.sc>=0 && dis[z.fs][z.sc]>h.fs+ver[u.fs][u.sc]){
                dis[z.fs][z.sc]=h.fs+ver[u.fs][u.sc];
                pq.push({dis[z.fs][z.sc],z});
            }
            z={h.sc.fs,h.sc.sc+1};
            u=min(z,h.sc);
            if(z.sc<=k && dis[z.fs][z.sc]>h.fs+ver[u.fs][u.sc]){
                dis[z.fs][z.sc]=h.fs+ver[u.fs][u.sc];
                pq.push({dis[z.fs][z.sc],z});
            }
        }
        cout << n-dis[0][0] << "\n";
    }
    return 0;
}