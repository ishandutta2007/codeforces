#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

#define arr (int)(3e5+10)

vi reb[arr];
bool use[arr];
int n,m;
int pred[arr];
vi ans(0);

set<pii> edges;

void upd_ans(vi cur_ans)
{
    if (ans.empty()||len(cur_ans)<len(ans)){
        ans=cur_ans;
    }
}

void bfs()
{
    queue<int> q;
    q.push(1);
    use[1]=1;
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (auto wh:reb[now]){
            if (!use[wh]){
                use[wh]=1;
                q.push(wh);
                pred[wh]=now;
            }
        }
    }
    if (use[n]){
        vi cur_ans(0);
        int cur=n;
        while (cur!=1){
            cur_ans.pb(cur);
            cur=pred[cur];
        }
        cur_ans.pb(1);
        reverse(all(cur_ans));
        upd_ans(cur_ans);
    }
}

int num[arr];
vi ways[arr];
int cnt;

void another_algo()
{
    int c1=0;
    for (int i=2;i<=n;i++){
        c1+=use[i];
    }

    if (len(reb[1])!=c1){
        for (int i=1;i<=n;i++){
            if (edges.count({1,i})){
                for (auto j:reb[i]){
                    if (j!=1&&!edges.count({1,j})){
                        vi cur_ans(0);
                        cur_ans.pb(1);
                        cur_ans.pb(i);
                        cur_ans.pb(j);
                        cur_ans.pb(1);
                        cur_ans.pb(n);
                        upd_ans(cur_ans);
                        return;
                    }
                }
            }
        }
    }
    else{
//        for (int i=2;i<=n;i++){
//            if (use[i]){
//                for (int j=0;j<len(reb[i]);j++){
//                    for (int k=j+1;k<len(reb[i]);k++){
//                        if (reb[i][j]!=1&&reb[i][k]!=1){
//                            if (!edges.count({reb[i][j],reb[i][k]})){
//                                int I=reb[i][j];
//                                int J=i;
//                                int K=reb[i][k];
//                                vi cur_ans(0);
//                                cur_ans.pb(1);
//                                cur_ans.pb(I);
//                                cur_ans.pb(J);
//                                cur_ans.pb(K);
//                                cur_ans.pb(I);
//                                cur_ans.pb(n);
//                                upd_ans(cur_ans);
//                                return;
//                            }
//                        }
//                    }
//                }
//            }
//        }
        for (int i=2;i<=n;i++){
            if (use[i]){
                set<int> nums;
                nums.clear();
                for (auto wh:reb[i]){
                    if (num[wh]){
                        nums.insert(num[wh]);
                    }
                }
                if (len(nums)==0){
                    num[i]=++cnt;
                    ways[cnt].pb(i);
                }
                elif (len(nums)==1){
                    int have=-1;
                    int not_have=-1;
                    for (auto wh:ways[*nums.begin()]){
                        if (edges.count({i,wh})){
                            have=wh;
                        }
                        else{
                            not_have=wh;
                        }
                    }
                    if (not_have==-1){
                        num[i]=*nums.begin();
                        ways[*nums.begin()].pb(i);
                    }
                    else{
                        int I=i;
                        int J=have;
                        int K=not_have;

                        vi cur_ans(0);
                        cur_ans.pb(1);
                        cur_ans.pb(I);
                        cur_ans.pb(J);
                        cur_ans.pb(K);
                        cur_ans.pb(I);
                        cur_ans.pb(n);
                        upd_ans(cur_ans);
                        return;
                    }
                }
                else{
                    int num1=*nums.begin();
                    nums.erase(nums.begin());
                    int num2=*nums.begin();
                    nums.erase(nums.begin());
                    int kek1=-1;
                    int kek2=-1;
                    for (auto wh:reb[i]){
                        if (num[wh]==num1){
                            kek1=wh;
                        }
                        if (num[wh]==num2){
                            kek2=wh;
                        }
                    }

                    int I=kek1;
                    int J=i;
                    int K=kek2;

                    vi cur_ans(0);
                    cur_ans.pb(1);
                    cur_ans.pb(I);
                    cur_ans.pb(J);
                    cur_ans.pb(K);
                    cur_ans.pb(I);
                    cur_ans.pb(n);
                    upd_ans(cur_ans);
                    return;
                }
            }
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if (min(u,v)==1&&max(u,v)==n){
            cout<<1<<"\n";
            cout<<1<<" "<<n<<"\n";
            return 0;
        }
        edges.insert({u,v});
        edges.insert({v,u});
        reb[u].pb(v);
        reb[v].pb(u);
    }
    bfs();
    if (len(ans)<=3&&!ans.empty()){
        cout<<len(ans)-1<<"\n";
        for (auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
        return 0;
    }
    another_algo();
    if (ans.empty()){
        cout<<-1<<"\n";
    }
    else{
        cout<<len(ans)-1<<"\n";
        for (auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}