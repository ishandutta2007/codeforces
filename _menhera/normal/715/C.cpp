#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<pair<int,int> > conn[101010];
bool visit[101010];
bool ran[101010];
int size[101010];
int maxst[101010];

vector<int> gX;

int calcSize(int a, int pa)
{
	if(ran[a]) return 0;
	size[a] = 1;
	maxst[a] = 0;
	gX.push_back(a);
	for(const auto& x: conn[a])
	{
		if(x.first == pa) continue;
		int c = calcSize(x.first, a);
		size[a] += c;
		maxst[a] = max(maxst[a], c);
	}
	return size[a];
}

int findCentroid(int i)
{
	gX.clear();
	int tS = calcSize(i, -1);
	int minv = N;
	int mini = i;
	for(const int& e: gX)
	{
		int v = max(maxst[e],tS-size[e]);
		if(minv>v)
		{
			minv = v; 
			mini = e;
		}
	}
	return mini;
}



int pow(int a, int b)
{
	if(b==0) return 1%M;
	if(b==1) return a%M;
	long long ans = pow(a, b/2);
	ans *= ans;
	ans %= M;
	if(b&1)
	{
		ans *= a;
		ans %= M;
	}
	return ans;
}

int inv10;


vector<int> st;
vector<int> stR;

void bktk(int a, int pa, int invP, int stx, int tenP, int stRx)
{
	if(ran[a]) return;
	if(pa!=-1)
	{
		st.push_back(stx);
		stR.push_back(stRx);
	}
	invP = (1LL*invP*inv10)%M;
	tenP = (1LL*tenP*10)%M;
	for(const auto& e: conn[a])
	{
		int tg = e.first;
		int w = e.second;
		if(tg == pa) continue;
		bktk(tg, a, invP , (stx + ((1LL*invP*w)%M ) )%M, tenP, (stRx+1LL*tenP*w)%M);
	}
}

long long findMatch(vector<int> &a, vector<int> &b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ans = 0;
	for(const int &x: a)
		ans += upper_bound(b.begin(), b.end(), x)-lower_bound(b.begin(), b.end(), x);
	return ans;
}


long long calc(int c)
{
	long long ans =0; 
	vector<int> ff;
	vector<int> gg;
	for(const auto &e: conn[c])
	{
		st.clear(); stR.clear();
		bktk(e.first, c, M-inv10, (1LL*e.second*(M-inv10))%M , 1, e.second%M);
		ans -= findMatch(st, stR);
		for(int i=0; i<st.size();i++)
			ff.push_back(st[i]);
		for(int i=0; i<stR.size();i++)
			gg.push_back(stR[i]);
	}
	ff.push_back(0);
	gg.push_back(0);
	ans += findMatch(ff, gg);
	return ans-1;
}

int phi(int a)
{
	if(a==1) return 0;
	int ra = a;
	int ans = a;
	for(int i=2; i*i<=ra; i++)
	{
		if(ra%i==0)
		{
			ans = (ans / i)*(i-1);
			while(ra%i==0) ra /= i;
		}
	}
	//printf("%d %d\n",ans,ra);
	if(ra!=1) ans = (ans/ra)*(ra-1);
	//printf("%d\n",ans);
	return ans;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1; i<N; i++)
	{
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		conn[u].emplace_back(v, w);
		conn[v].emplace_back(u, w);
	}
	inv10 = pow(10, phi(M)-1);
	//printf("==%d==\n",inv10);
	long long ans = 0;
	for(int i=0; i<N; )
	{
		if(ran[i])
		{
			++i;
			continue;
		}
		int c = findCentroid(i);
		ans += calc(c);
		ran[c] = true;
	}
	printf("%lld\n",ans);
}