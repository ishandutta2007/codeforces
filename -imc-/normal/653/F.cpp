#include <bits/stdc++.h>

using namespace std;

const int maxSigma = 2, maxN = 5e5 + 100;

struct state
{
	int length;
	int link;
	vector<int> invLink;
	int transition[maxSigma];
	int firstPos;
	int nOcc;
	
	int queryAnswer;
	
	void init(int l)
	{
		nOcc = 0;
		firstPos = -1;
		length = l;
		link = -1;
		memset(transition, -1, sizeof(transition));
	}
};

state states[2 * maxN];
int lastState = 0;
int nStates = 1;

void dump()
{
	printf("%d states, %d lastState:\n", nStates, lastState);
	for (int i = 0; i < nStates; i++)
	{
		printf("state %d, length %d, link %d\n", i, states[i].length, states[i].link);
		for (int c = 0; c < maxSigma; c++)
			if (states[i].transition[c] != -1)
				printf("  transition by %c to %d\n", 'a' + c, states[i].transition[c]);
	}
	printf("\n");
}

void addSymbol(int c)
{
	c -= '(';
	
	int newState = nStates++;
	states[newState].init(states[lastState].length + 1);
	states[newState].firstPos = states[lastState].length;
	states[newState].nOcc = 1;
	
	int p = lastState;
	while (p != -1 && states[p].transition[c] == -1)
	{
		states[p].transition[c] = newState;
		p = states[p].link;
	}
	
	if (p == -1)
		states[newState].link = 0;
	else if (states[p].length + 1 == states[states[p].transition[c]].length)
		states[newState].link = states[p].transition[c];
	else
	{
		int q = states[p].transition[c];
		int qClone = nStates++;
		states[qClone] = states[q];
		states[qClone].length = states[p].length + 1;
		states[qClone].nOcc = 0;
		states[q].link = qClone;
		
		while (p != -1 && states[p].transition[c] == q)
		{
			states[p].transition[c] = qClone;
			p = states[p].link;
		}
		
		states[newState].link = qClone;
	}
	lastState = newState;
	
	//dump();
}

typedef long long ll;

int n;
string s;

vector<int> pref;
vector<int> nextLess;
map<int, vector<int>> valueToOcc;

int value(char c)
{
    return c == '(' ? 1 : -1;
}

void prebuild()
{
    pref.resize(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = (pref[i - 1]) + value(s[i - 1]);
    
    nextLess.resize(n + 1, n + 1);
    vector<pair<int, int>> st; // value, index
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && st.back().first > pref[i])
        {
            nextLess[st.back().second] = i;
            st.pop_back();
        }
        st.push_back(make_pair(pref[i], i));
    }
    
    for (int i = 0; i <= n; i++)
        valueToOcc[pref[i]].push_back(i);
}

int query(int L, int l, int r)
{
    // first pos in L
    // last pos in [l, r]
    /*printf("%d %d %d\n", L, l, r);
    for (int i = L; i <= r; i++)
        printf("%c", s[i]);
    printf("\n");*/
    assert(l >= L);
    assert(l <= r);
    
    int ans = 0;
    
    /*int balance = 0;
    int minBalance = 0;
    for (int i = L; i <= r; i++)
    {
        balance += s[i] == '(' ? 1 : -1;
        minBalance = min(balance, minBalance);
        if (i >= l && minBalance >= 0 && balance == 0)
            ans++;
    }*/
    
    int fastAns = 0;
    
    int untilCan = nextLess[L] - 1;
    r = min(r, untilCan - 1);
    if (r < l)
        fastAns = 0;
    else
    {
        vector<int>& occ = valueToOcc[pref[L]];
        fastAns = lower_bound(occ.begin(), occ.end(), r + 2) - lower_bound(occ.begin(), occ.end(), l + 1);
    }
    
    //printf("ans: %d, fast ans: %d\n", ans, fastAns);
    //assert(fastAns == ans);
    return fastAns;
}

void solve()
{
	states[0].init(0);
	
    cin >> n;
	cin >> s;
    
    //printf("%s\n", s.c_str());
	
	for (char c: s)
		addSymbol(c);
    
    ll answer = 0;
	
	vector<vector<int>> lenStates(s.size() + 1);
	for (int i = 0; i < nStates; i++)
		lenStates[states[i].length].push_back(i);
	for (int i = s.size(); i >= 0; i--)
		for (int s: lenStates[i])
			states[states[s].link].nOcc += states[s].nOcc;
    
    reverse(s.begin(), s.end());
    for (char& c: s)
        if (c == '(')
            c = ')';
        else
            c = '(';
        
    prebuild();
        
	for (int i = 1; i < nStates; i++)
    {
        int r = states[i].firstPos;
        int len = states[i].length;
        //int l = r - len + 1;
        int pLen = states[states[i].link].length;
        
        //printf("%d %d %d\n", l, len, pLen);
        
        int l = n - r - 1;
        answer += query(l, l + pLen, l + len - 1);
    }
    cout << answer << endl;
    /*
	
	for (int i = 1; i < nStates; i++)
		states[states[i].link].invLink.push_back(i);
	
	int n = s.size();
	vector<int> prefixSum(n);
	for (int i = 0; i < n; i++)
		prefixSum[i] = (i ? prefixSum[i - 1] : 0) + (s[i] == '0' ? 1 : -1);
	
	vector<int> leftBound(n);
	vector<int> sumLastIndex(2 * (n + 1), -1);
	for (int i = 0; i < n; i++)
	{
		sumLastIndex[prefixSum[i] + (n + 1)] = i;
		leftBound[i] = sumLastIndex[prefixSum[i] - 1 + (n + 1)];
	}
	
	vector<vector<pair<int, int>>> queryFirst(n + 1);
	
	for (int i = 1; i < nStates; i++)
	{
		int R = states[i].firstPos;
		int L = max(leftBound[R], R - states[i].length);
		//printf("end %d (need sum %d): min acceptable %d\n", R, prefixSum[R], L);
		queryFirst[L + 1].push_back(make_pair(prefixSum[R], i));
	}
	
	sumLastIndex.assign(2 * (n + 1), n);
	
	for (int i = n; i >= 0; i--)
	{
		if (i != 0)
			sumLastIndex[prefixSum[i - 1] + n + 1] = i - 1;
		else
			sumLastIndex[0 + n + 1] = -1;
		
		for (pair<int, int> p: queryFirst[i])
			states[p.second].queryAnswer = sumLastIndex[p.first + n + 1];
	}
	
	ll prodMax = 0;
	int bestL = -1, bestR = -1;
	
	for (int i = 1; i < nStates; i++)
	{
		int R = states[i].firstPos;
		int L = states[i].queryAnswer + 1;
		
		//printf("end %d: query answer %d\n", R, states[i].queryAnswer);
		
		ll prod = (R - L + 1) * (ll)states[i].nOcc;
		if (prod > prodMax)
		{
			prodMax = prod;
			bestL = L;
			bestR = R;
		}
		
		//printf("state %d: substring %d..%d ('%s'), %d occurences\n", i, L, R, s.substr(L, R - L + 1).c_str(), states[i].nOcc);
	}
	
	assert(prodMax > 0);
	printf("%lld\n%s\n", prodMax, s.substr(bestL, bestR - bestL + 1).c_str());*/
}

int main()
{
	solve();

	return 0;
}