    #include <bits/stdc++.h>
    using namespace std;
    const int N = 100005;
    struct ban
    {
        int x;
        long long q;
        ban(){}
        ban(int x, long long q)
        {
            this->x = x;
            this->q = q;
        }
    };

    int n;
    long long k;
    long long a[N];

    map<int, int> mp;
    map<int, vector<int> > v;

    int main()
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            mp[a[i]]++;
            v[a[i]].push_back(i);
        }

        long long p = 0;
        long long q = 0;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
        {
            long long qq = min(it->first - q, (k / (n - p)));
            if (qq == 0)
            {
                break;
            }
            k -= (qq * (n - p));
            q += qq;
            p += (it->second);
        }

        deque<int> dq;
        for (int i = 1; i <= n; ++i)
        {
            a[i] -= q;
            if (a[i] > 0)
                dq.push_back(i);
        }

        while (k--)
        {
            if (dq.empty())
            {
                cout << "-1" << endl;
                return 0;
            }
            a[dq.front()]--;
            if (a[dq.front()] > 0)
                dq.push_back(dq.front());
            dq.pop_front();
        }

        while (!dq.empty())
        {
            cout << dq.front() << ' ';
            dq.pop_front();
        }
        return 0;
    }