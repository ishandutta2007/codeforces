#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define y eth
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=6e5+100;
const int MAXN=arr;

int ver;
int n, bridges, par[MAXN], bl[MAXN], comp[MAXN], siz[MAXN],tutu[MAXN];
int k,m;

void init() {
	for (int i=0; i<n; ++i) {
		bl[i] = comp[i] = i;
		siz[i] = 1;
		par[i] = -1;
	}
	bridges = 0;
}


int get (int v) {
	if (v==-1)  return -1;
	return bl[v]==v ? v : bl[v]=get(bl[v]);
}

int get_comp (int v) {
	v = get(v);
	return comp[v]==v ? v : comp[v]=get_comp(comp[v]);
}

void make_root (int v) {
	v = get(v);
	int root = v,
		child = -1;
    int costup1=0;
	while (v != -1) {
		int costup2=tutu[v];
		int p = get(par[v]);
		par[v] = child;
		tutu[v]=costup1;
		comp[v] = root;
		child=v;  v=p;
		costup1=costup2;
	}
	siz[root] = siz[child];
}


int cu, u[MAXN];

void merge_path (int a, int b) {
	++cu;


	vector<pair<int,int> > va, vb;
	int lca = -1;
	int pr=0;
	for(;;) {
		if (a != -1) {
			a = get(a);
			va.pb ({a,tutu[a]});

			if (u[a] == cu) {
				lca = a;
				break;
			}
			u[a] = cu;
            pr=tutu[a];
			a = par[a];
		}

		if (b != -1) {
			b = get(b);
			vb.pb ({b,tutu[b]});

			if (u[b] == cu) {
				lca = b;
				break;
			}
			u[b] = cu;
			pr=tutu[b];

			b = par[b];
		}
	}

	for (size_t i=0; i<va.size(); ++i) {
		bl[va[i].fir] = lca;
		if (va[i].fir == lca)  break;
		--bridges;
        ver+=va[i].sec;
	}
	for (size_t i=0; i<vb.size(); ++i) {
		bl[vb[i].fir] = lca;
		if (vb[i].fir == lca)  break;
		--bridges;
		ver+=vb[i].sec;
	}
}


void add_edge (int a, int b, int cost) {
	a = get(a);   b = get(b);
	if (a == b)  return;

	int ca = get_comp(a),
		cb = get_comp(b);
	if (ca != cb)
    {
		++bridges;
		if (siz[ca] > siz[cb]) {
			swap (a, b);
			swap (ca, cb);
		}
		make_root (a);
		tutu[a]=cost;
		par[a] = comp[a] = b;
		siz[cb] += siz[a];
	}
	else
		merge_path (a, b);
}


signed main()
{
    fast;
    n,k,m;
    cin>>n>>k>>m;

    init();

    for (int i =1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        add_edge(a,b,1);
    }

    int sum=0;
    int ans=0;

    vector<pair<int,pair<int,int> > > reb;

    for (int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        reb.pb({c,{a,b}});
    }

    sort(reb.begin(),reb.end());

    for (auto i:reb)
    {
        ver=0;
        add_edge(i.sec.fir,i.sec.sec,0);
        sum+=ver;
        ans+=i.fir*ver;
    }

    if (sum!=k)
        cout<<-1; else
        cout<<ans;

}