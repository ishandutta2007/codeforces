/*
*         Just close your eyes
*                 The sun is going down
*                         You'll be alright...
*                                 No one can hurt you now
*                                         Come, morning light...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=998244353;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[8][3];
int perm[8][3];
const int permu[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
const int pows[8]={1,6,36,216,1296,7776,46656,279936};
inline ll dist(int i, int j)
{
        return (perm[i][0]-perm[j][0])*(perm[i][0]-perm[j][0])+(perm[i][1]-perm[j][1])*(perm[i][1]-perm[j][1])+(perm[i][2]-perm[j][2])*(perm[i][2]-perm[j][2]);
}
ll dists[8][8];
void solve() {
        for(int i=0; i<8; i++)
                for(int j=0; j<3; j++)
                        cin>>arr[i][j];
        int lul=1679716;
        for(int i=0; i<lul; i+=6) {
                for(int j=0; j<8; j++)
                {
                        int te=(i/pows[j])%pows[1];
                        perm[j][0]=arr[j][permu[te][0]];
                        perm[j][1]=arr[j][permu[te][1]];
                        perm[j][2]=arr[j][permu[te][2]];
                }
                bool yes=1;
                for(int j=0; j<8; j++)
                {
                        for(int k=0; k<8; k++)
                                dists[j][k]=dist(j,k);
                        sort(dists[j],dists[j]+8);
                }
                for(int j=1; j<8; j++)
                        for(int k=0; k<8; k++)
                                if(dists[j][k]!=dists[0][k])
                                        yes=0;
                for(int j=0; j<8; j++)
                {
                        if(dists[j][1]!=dists[j][2]||dists[j][2]!=dists[j][3]||dists[j][2]==0)
                                yes=0;
                        if(dists[j][4]!=dists[j][5]||dists[j][5]!=dists[j][6])
                                yes=0;
                        if(dists[j][4]!=2*dists[j][2]||dists[j][7]!=3*dists[j][2])
                                yes=0;
                }
                if(yes)
                {
                        cout<<"YES"<<endl;
                        for(int i=0; i<8; i++,cout<<endl)
                                for(int j=0; j<3; j++)
                                        cout<<perm[i][j]<<" ";
                        exit(0);
                }
        }
        cout<<"NO"<<endl;
}
signed main() {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        srand(chrono::steady_clock::now().time_since_epoch().count());
        auto clk=clock();
        int t=1;
//        cin>>t;
        while(t--)
                solve();
#ifdef rd
        cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
        return 0;
}