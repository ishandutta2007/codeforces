#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
char a[N];

int q[26];

int anss;
char ans[N];

void solv()
{
    anss = 0;

    memset(q, 0, sizeof q);

    for (int i = 0; i < n; ++i)
    {
        q[a[i] - 'a']++;
    }

    char minu = a[0];
    for (int i = 0; i < n; ++i)
    {
        minu = min(minu, a[i]);
    }

    if (q[minu - 'a'] == n)
    {
        for (int i = 0; i < n; ++i)
            ans[anss++] = minu;
        cout << a << "\n";
        return;
    }

    for (char j = 'a'; j <= 'z'; ++j)
    {
        if (q[j - 'a'] == 1)
        {
            ans[anss++] = j;
            cout << j;
            q[j - 'a']--;
            while (1)
            {
                bool f = false;
                for (char j = 'a'; j <= 'z'; ++j)
                {
                    if (q[j - 'a'])
                    {
                        --q[j - 'a'];
                        cout << j;
                        ans[anss++] = j;
                        f = true;
                        break;
                    }
                }
                if (!f)
                    break;
            }
            cout << "\n";
            return;
        }
    }

    if (n - q[minu - 'a'] >= q[minu - 'a'] - 2)
    {
        ans[anss++] = minu;
        cout << minu;
        --q[minu - 'a'];
        for (int i = 0; i < n - 1; ++i)
        {
            if (q[minu - 'a'])
            {
                --q[minu - 'a'];
                cout << minu;
                ans[anss++] = minu;
            }
            for (char j = minu + 1; j <= 'z'; ++j)
            {
                if (q[j - 'a'])
                {
                    --q[j - 'a'];
                    cout << j;
                    ans[anss++] = j;
                    break;
                }
            }
        }
        cout << "\n";
    }
    else
    {
        char min2;
        for (char j = minu + 1; j <= 'z'; ++j)
        {
            if (q[j - 'a'])
            {
                min2 = j;
                break;
            }
        }
        if (q[minu - 'a'] + q[min2 - 'a'] == n)
        {
            cout << minu;
            ans[anss++] = minu;
            --q[minu - 'a'];
            for (int i = 0; i < n - 1; ++i)
            {
                if (q[min2 - 'a'])
                {
                    --q[min2 - 'a'];
                    cout << min2;
                    ans[anss++] = min2;
                }
                else
                {
                    --q[minu - 'a'];
                    cout << minu;
                    ans[anss++] = minu;
                }
            }
            cout << "\n";
        }
        else
        {
            cout << minu;
            cout << min2;
            ans[anss++] = minu;
            ans[anss++] = min2;
            --q[minu - 'a'];
            --q[min2 - 'a'];
            while (q[minu - 'a'])
            {
                cout << minu;
                --q[minu - 'a'];
                ans[anss++] = minu;
            }
            for (char j = min2 + 1; j <= 'z'; ++j)
            {
                if (q[j - 'a'])
                {
                    cout << j;
                    --q[j - 'a'];
                    ans[anss++] = j;
                    break;
                }
            }
            while (1)
            {
                bool f = false;
                for (char j = minu + 1; j <= 'z'; ++j)
                {
                    if (q[j - 'a'])
                    {
                        --q[j - 'a'];
                        cout << j;
                        ans[anss++] = j;
                        f = true;
                        break;
                    }
                }
                if (!f)
                    break;
            }
            cout << "\n";
        }
    }
}

vector<int> z_function_trivial()
{
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i)
    {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && a[z[i]] == a[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

void solv0()
{
    sort(a, a + n);
    int ansz = n + 1;
    string ans;
    do
    {
        vector<int> z = z_function_trivial();
        int maxu = z[0];
        for (int i = 1; i < n; ++i)
            maxu = max(maxu, z[i]);
        string s = "";
        for (int i = 0; i < n; ++i)
            s += a[i];
        if (maxu < ansz)
        {
            ansz = maxu;
            ans = s;
        }
        else if (maxu == ansz)
        {
            //cout << s << "\n";
            ans = min(ans, s);
        }
    } while (next_permutation(a, a + n));
    cout << ans << "\n";
    for (int i = 0; i < n; ++i)
    {
        /*if (ans[i] != ::ans[i])
        {
            cout << "WA\n";
            return;
        }*/
        assert(ans[i] == ::ans[i]);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 100;
    while (st--)
    {
        n = rnf() % 6 + 1;
        for (int i = 0; i < n; ++i)
            a[i] = rnf() % 26 + 'a';
        solv();
        solv0();
    }
    return 0;*/

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        cin >> a;
        n = strlen(a);
        solv();
        //solv0();
    }
    return 0;
}