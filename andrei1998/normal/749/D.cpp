#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 200000 + 5;

int a[NMAX];
int b[NMAX];

vector <int> freq[NMAX];

int cnt;
int absent[NMAX];

int getAnswer(int pos) {
    int ans = 0;
    for (int i = 0; i < cnt; ++ i) {
        vector <int> &v = freq[absent[i]];
        ans += v.end() - lower_bound(v.begin(), v.end(), pos);
    }

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++ i) {
        cin >> a[i] >> b[i];
        freq[a[i]].push_back(i);
    }

    int q = 0;
    cin >> q;

    while (q --) {
        cin >> cnt;

        for (int i = 0; i < cnt; ++ i)
            cin >> absent[i];

        int st = 1;
        int dr = N;
        int ans = N + 1;

        while (st <= dr) {
            int mid = (st + dr) >> 1;
            if (getAnswer(mid) == N - mid + 1) {
                ans = mid;
                dr = mid - 1;
            }
            else
                st = mid + 1;
        }

        if (ans == 1)
            cout << "0 0\n";
        else {
            -- ans;
            int who = a[ans];
            cout << who << ' ';

            absent[cnt ++] = who;

            st = 1;
            dr = N;
            ans = N + 1;

            while (st <= dr) {
                int mid = (st + dr) >> 1;
                if (getAnswer(mid) == N - mid + 1) {
                    ans = mid;
                    dr = mid - 1;
                }
                else
                    st = mid + 1;
            }

            vector <int> &v = freq[who];
            ans = *lower_bound(v.begin(), v.end(), ans);
            cout << b[ans] << '\n';
        }
    }
    return 0;
}