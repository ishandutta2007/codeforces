#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

map<pair<pii,int>,int> use;
map<pair<pii,int>,int> cnt;

bool is_use(int xx,int yy)
{
    int sum=0;
    sum+=use[mp(mp(xx,yy),1)];
    sum+=use[mp(mp(xx,yy),2)];
    sum+=use[mp(mp(xx,yy),3)];
    sum+=use[mp(mp(xx,yy),4)];
    sum+=use[mp(mp(xx,yy),5)];
    sum+=use[mp(mp(xx,yy),6)];
    sum+=use[mp(mp(xx,yy),7)];
    sum+=use[mp(mp(xx,yy),8)];
    //if (sum>=1)
      //  cout<<xx<<" "<<yy<<"\n";
    return sum>=1;
}

void next(pii& a,int wh)
{
    if (wh==1)
        a.fir++;
    if (wh==2)
        a.fir++,
        a.sec++;
    if (wh==3)
        a.sec++;
    if (wh==4)
        a.fir--,
        a.sec++;
    if (wh==5)
        a.fir--;
    if (wh==6)
        a.fir--,
        a.sec--;
    if (wh==7)
        a.sec--;
    if (wh==8)
        a.fir++,
        a.sec--;
}

main()
{
    int n;
    cin>>n;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    queue<pair<pii,int>> q;
    q.push(mp(mp(0,0),1));
    use[mp(mp(0,0),1)]=1;
    cnt[mp(mp(0,0),1)]=1;
    bool lalka=true;
    for (auto i:a)
    {
        //cout<<"new i :: "<<i<<"\n";
        queue<pair<pii,int>> new_q;
        set<pair<pii,int>> setik;
        setik.clear();
        while (!q.empty())
        {
            setik.insert(q.front());
            q.pop();
        }
        for (auto i:setik)
            q.push(i);
        while (!q.empty())
        {
            bool laal=false;
            auto now=q.front();
            //cout<<"queue :: "<<now.fir.fir<<" "<<now.fir.sec<<" "<<now.sec<<"\n";
            q.pop();
            int cnt_oper=i-1;
            while (cnt_oper--)
            {
                use[now]=true;
                if (laal) break;
                next(now.fir,now.sec);
                use[now]=true;
            }
            use[now]=true;
            if (!laal)
            {
                now.sec--;
                if (now.sec==0)
                    now.sec=8;
                auto dop=now;
                next(dop.fir,dop.sec);
                new_q.push(dop);
                now.sec+=2;
                now.sec%=8;
                if (now.sec==0)
                    now.sec=8;
                dop=now;
                next(dop.fir,dop.sec);
                new_q.push(dop);
            }
        }
        q=new_q;
        lalka=false;
    }
    int ans=0;
    for (int i=-300;i<=300;i++)
        for (int j=-300;j<=300;j++)
            ans+=is_use(i,j);
    cout<<ans;
}