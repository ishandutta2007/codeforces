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
const int N = 200005;

char s[N], t[N];

vector<pair<int, int> > ans0;
int solv()
{
    vector<pair<int, int> > ans;

    int n = strlen(s);
    deque<pair<char, int> > vs;
    vs.push_back(m_p(s[0], 1));
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == vs.back().fi)
            ++vs.back().se;
        else
            vs.push_back(m_p(s[i], 1));
    }

    n = strlen(t);
    deque<pair<char, int> > vt;
    vt.push_back(m_p(t[0], 1));
    for (int i = 1; i < n; ++i)
    {
        if (t[i] == vt.back().fi)
            ++vt.back().se;
        else
            vt.push_back(m_p(t[i], 1));
    }

    if (vs[0].fi == vt[0].fi && vs.back().fi != vt.back().fi && sz(vs) >= 2 && sz(vt) >= 2)
    {
        if (vs.size() > vt.size())
        {
            int minu = N;
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi != vt[0].fi)
                {
                    minu = min(minu, abs(sz(vs) - i - 1 - (sz(vt) + i - 1)));
                }
            }
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi != vt[0].fi)
                {
                    if (minu == abs(sz(vs) - i - 1 - (sz(vt) + i - 1)))
                    {
                        int ps = 0;
                        for (int j = 0; j <= i; ++j)
                            ps += vs[j].se;
                        ans.push_back(m_p(ps, vt[0].se));

                        vector<pair<char, int> > u;
                        for (int j = 0; j <= i; ++j)
                        {
                            u.push_back(vs.front());
                            vs.pop_front();
                        }

                        vs.front().se += vt.front().se;
                        vt.pop_front();

                        if (vt.empty())
                            vt.push_back(u.back());
                        else
                            vt.front().se += u.back().se;
                        u.pop_back();
                        while (!u.empty())
                        {
                            vt.push_front(u.back());
                            u.pop_back();
                        }
                        break;
                    }
                }
            }
        }
        else if (sz(vt) != 1 || sz(vs) != 1)
        {
            swap(vs, vt);

            int minu = N;
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi != vt[0].fi)
                {
                    minu = min(minu, abs(sz(vs) - i - 1 - (sz(vt) + i - 1)));
                }
            }
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi != vt[0].fi)
                {
                    if (minu == abs(sz(vs) - i - 1 - (sz(vt) + i - 1)))
                    {
                        int ps = 0;
                        for (int j = 0; j <= i; ++j)
                            ps += vs[j].se;
                        ans.push_back(m_p(ps, vt[0].se));

                        vector<pair<char, int> > u;
                        for (int j = 0; j <= i; ++j)
                        {
                            u.push_back(vs.front());
                            vs.pop_front();
                        }

                        vs.front().se += vt.front().se;
                        vt.pop_front();

                        if (vt.empty())
                            vt.push_back(u.back());
                        else
                            vt.front().se += u.back().se;
                        u.pop_back();
                        while (!u.empty())
                        {
                            vt.push_front(u.back());
                            u.pop_back();
                        }
                        break;
                    }
                }
            }

            swap(vs, vt);
            swap(ans.back().fi, ans.back().se);
        }
    }

    //////////////////////////////////////////////////////////

    if (vs[0].fi == vt[0].fi)
    {
        if (vs.size() > vt.size())
        {
            int minu = N;
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi == vt[0].fi)
                {
                    minu = min(minu, abs(sz(vs) - i - 1 - (sz(vt) + i)));
                }
            }
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi == vt[0].fi)
                {
                    if (minu == abs(sz(vs) - i - 1 - (sz(vt) + i)))
                    {
                        int ps = 0;
                        for (int j = 0; j <= i; ++j)
                            ps += vs[j].se;

                        ans.push_back(m_p(ps, 0));

                        vector<pair<char, int> > u;
                        for (int j = 0; j <= i; ++j)
                        {
                            u.push_back(vs.front());
                            vs.pop_front();
                        }

                        vt.front().se += u.back().se;
                        u.pop_back();
                        while (!u.empty())
                        {
                            vt.push_front(u.back());
                            u.pop_back();
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            swap(vs, vt);

            int minu = N;
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi == vt[0].fi)
                {
                    minu = min(minu, abs(sz(vs) - i - 1 - (sz(vt) + i)));
                }
            }
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i].fi == vt[0].fi)
                {
                    if (minu == abs(sz(vs) - i - 1 - (sz(vt) + i)))
                    {
                        int ps = 0;
                        for (int j = 0; j <= i; ++j)
                            ps += vs[j].se;

                        ans.push_back(m_p(ps, 0));

                        vector<pair<char, int> > u;
                        for (int j = 0; j <= i; ++j)
                        {
                            u.push_back(vs.front());
                            vs.pop_front();
                        }

                        vt.front().se += u.back().se;
                        u.pop_back();
                        while (!u.empty())
                        {
                            vt.push_front(u.back());
                            u.pop_back();
                        }
                        break;
                    }
                }
            }

            swap(vs, vt);
            swap(ans.back().fi, ans.back().se);
        }
    }

    assert(vs[0].fi != vt[0].fi);
    if (vs.size() > vt.size())
    {
        int minu = N;
        for (int i = 0; i < vs.size(); ++i)
        {
            if (vs[i].fi != vt[0].fi)
            {
                minu = min(minu, abs(sz(vs) - i - 1 - (sz(vt) + i - 1)));
            }
        }
        for (int i = 0; i < vs.size(); ++i)
        {
            if (vs[i].fi != vt[0].fi)
            {
                if (minu == abs(sz(vs) - i - 1 - (sz(vt) + i - 1)))
                {
                    int ps = 0;
                    for (int j = 0; j <= i; ++j)
                        ps += vs[j].se;
                    ans.push_back(m_p(ps, vt[0].se));

                    vector<pair<char, int> > u;
                    for (int j = 0; j <= i; ++j)
                    {
                        u.push_back(vs.front());
                        vs.pop_front();
                    }

                    vs.front().se += vt.front().se;
                    vt.pop_front();

                    if (vt.empty())
                        vt.push_back(u.back());
                    else
                        vt.front().se += u.back().se;
                    u.pop_back();
                    while (!u.empty())
                    {
                        vt.push_front(u.back());
                        u.pop_back();
                    }
                    break;
                }
            }
        }
    }
    else if (sz(vt) != 1 || sz(vs) != 1)
    {
        swap(vs, vt);

        int minu = N;
        for (int i = 0; i < vs.size(); ++i)
        {
            if (vs[i].fi != vt[0].fi)
            {
                minu = min(minu, abs(sz(vs) - i - 1 - (sz(vt) + i - 1)));
            }
        }
        for (int i = 0; i < vs.size(); ++i)
        {
            if (vs[i].fi != vt[0].fi)
            {
                if (minu == abs(sz(vs) - i - 1 - (sz(vt) + i - 1)))
                {
                    int ps = 0;
                    for (int j = 0; j <= i; ++j)
                        ps += vs[j].se;
                    ans.push_back(m_p(ps, vt[0].se));

                    vector<pair<char, int> > u;
                    for (int j = 0; j <= i; ++j)
                    {
                        u.push_back(vs.front());
                        vs.pop_front();
                    }

                    vs.front().se += vt.front().se;
                    vt.pop_front();

                    if (vt.empty())
                        vt.push_back(u.back());
                    else
                        vt.front().se += u.back().se;
                    u.pop_back();
                    while (!u.empty())
                    {
                        vt.push_front(u.back());
                        u.pop_back();
                    }
                    break;
                }
            }
        }

        swap(vs, vt);
        swap(ans.back().fi, ans.back().se);
    }

    while (1)
    {
        if (sz(vs) == 1 && sz(vt) == 1)
            break;

        pair<char, int> ss = vs.front();
        vs.pop_front();
        pair<char, int> tt = vt.front();
        vt.pop_front();

        ans.push_back(m_p(ss.se, tt.se));

        if (vs.empty())
            vs.push_back(tt);
        else
            vs.front().se += tt.se;

        if (vt.empty())
            vt.push_back(ss);
        else
            vt.front().se += ss.se;
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
    ans0 = ans;
    return sz(ans);
}

int dp[55][55][2][2];
bool mem[55][55][2][2];
int solv0(int s, char ss, int t, char tt)
{
    if (s == 1 && t == 1)
        return 0;
    if (mem[s][t][ss - 'a'][tt - 'a'])
        return dp[s][t][ss - 'a'][tt - 'a'];
    mem[s][t][ss - 'a'][tt - 'a'] = true;

    dp[s][t][ss - 'a'][tt - 'a'] = N;
    for (int sh = 0; sh <= s; ++sh)
    {
        for (int th = 0; th <= t; ++th)
        {
            deque<char> sv;
            for (int k = 0; k < s; ++k)
            {
                sv.push_back('a' + (ss - 'a' + k) % 2);
            }
            deque<char> tv;
            for (int k = 0; k < t; ++k)
            {
                tv.push_back('a' + (tt - 'a' + k) % 2);
            }

            vector<char> us;
            for (int k = 0; k < sh; ++k)
            {
                us.push_back(sv.front());
                sv.pop_front();
            }

            vector<char> ut;
            for (int k = 0; k < th; ++k)
            {
                ut.push_back(tv.front());
                tv.pop_front();
            }

            while (!us.empty())
            {
                tv.push_front(us.back());
                us.pop_back();
            }
            while (!ut.empty())
            {
                sv.push_front(ut.back());
                ut.pop_back();
            }

            int ns = 0;
            for (int i = 0; i < sz(sv); ++i)
            {
                if (i == 0 || sv[i] != sv[i - 1])
                    ++ns;
            }
            int nt = 0;
            for (int i = 0; i < sz(tv); ++i)
            {
                if (i == 0 || tv[i] != tv[i - 1])
                    ++nt;
            }

            if (ns == 0 || nt == 0)
                continue;

            char nss = sv[0];
            char ntt = tv[0];

            if (ns + nt == s + t)
                continue;

            dp[s][t][ss - 'a'][tt - 'a'] = min(dp[s][t][ss - 'a'][tt - 'a'], solv0(ns, nss, nt, ntt) + 1);
        }
    }

    return dp[s][t][ss - 'a'][tt - 'a'];
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 1000;
    while (st--)
    {
        int sn = rnf() % 15 + 1;
        int tn = rnf() % 15 + 2;

        int z = rnf() % 2;
        for (int i = 0; i < sn; ++i)
            s[i] = ('a' + (z + i) % 2);

        z = rnf() % 2;
        for (int i = 0; i < tn; ++i)
            t[i] = ('a' + (z + i + 1) % 2);

        s[sn] = t[tn] = 0;

        if (solv() != solv0(sn, s[0], tn, t[0]))
        {
            cout << "WA" << endl;
            cout << s << endl;
            cout << t << endl;
            cout << solv0(sn, s[0], tn, t[0]) << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < sn; ++i)
                s[i] = 'a' + rnf() % 2;
            for (int i = 0; i < tn; ++i)
                t[i] = 'a' + rnf() % 2;
            s[sn - 1] = 'a';
            t[tn - 1] = 'b';
            solv();
            deque<char> sv, tv;
            for (int i = 0; i < strlen(s); ++i)
                sv.push_back(s[i]);
            for (int i = 0; i < strlen(t); ++i)
                tv.push_back(t[i]);
            for (int i = 0; i < sz(ans0); ++i)
            {
                int sh = ans0[i].fi;
                int th = ans0[i].se;
                vector<char> us;
                for (int k = 0; k < sh; ++k)
                {
                    us.push_back(sv.front());
                    sv.pop_front();
                }

                vector<char> ut;
                for (int k = 0; k < th; ++k)
                {
                    ut.push_back(tv.front());
                    tv.pop_front();
                }

                while (!us.empty())
                {
                    tv.push_front(us.back());
                    us.pop_back();
                }
                while (!ut.empty())
                {
                    sv.push_front(ut.back());
                    ut.pop_back();
                }
            }
            for (int i = 0; i < sz(sv); ++i)
            {
                if (sv[i] != sv[0])
                {
                    cout << "WA" << endl;
                    cout << s << endl;
                    cout << t << endl;
                    return 0;
                }
            }
            for (int i = 0; i < sz(tv); ++i)
            {
                if (tv[i] != tv[0])
                {
                    cout << "WA" << endl;
                    cout << s << endl;
                    cout << t << endl;
                    return 0;
                }
            }
        }
    }
    cout << "OK" << endl;
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        cin >> s >> t;
        solv();
    }
    return 0;
}