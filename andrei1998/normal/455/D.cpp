#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

const int NMAX = 100000 + 5;
const int RAD = 480;

int whichBucket[NMAX];
int bucketLeft[NMAX];
int bucketRight[NMAX];
int buckets;

deque <int> dqs[(NMAX + RAD - 1) / RAD + 1];
int Maps[(NMAX + RAD - 1) / RAD + 1][NMAX];

int N, Q;
int a[NMAX];

void precompute() {
    for (int i = 1; i <= N; i += RAD) {
        bucketLeft[++ buckets] = i;
        for (int j = i; j <= N && j < i + RAD; ++ j) {
            bucketRight[buckets] = j;
            whichBucket[j] = buckets;
            dqs[buckets].push_back(a[j]);
            ++ Maps[buckets][a[j]];
        }
    }
}

int count(int val, int l, int r) {
    int lb = whichBucket[l];
    int rb = whichBucket[r];

    int ans = 0;
    if (lb == rb) {
        //Brute
        int start = bucketLeft[lb];
        for (int i = l; i <= r; ++ i)
            ans += (dqs[lb][i - start] == val);
    }
    else {
        //First part
        int start = bucketLeft[lb];
        for (int i = l; i <= bucketRight[lb]; ++ i)
            ans += (dqs[lb][i - start] == val);

        //Last part
        start = bucketLeft[rb];
        for (int i = start; i <= r; ++ i)
            ans += (dqs[rb][i - start] == val);

        //Middle part
        for (int b = lb + 1; b < rb; ++ b)
            ans += Maps[b][val];
    }

    return ans;
}

void shift(int l, int r) {
    int lb = whichBucket[l];
    int rb = whichBucket[r];

    if (lb == rb) {
        //Brute
        int start = bucketLeft[lb];

        int val = dqs[lb][r - start];
        dqs[lb].erase(dqs[lb].begin() + (r - start));
        dqs[lb].insert(dqs[lb].begin() + (l - start), val);
    }
    else {
        //First and last parts
        int start = bucketLeft[rb];

        //Erase at end
        int val = dqs[rb][r - start];
        dqs[rb].erase(dqs[rb].begin() + (r - start));
        Maps[rb][val] --;

        //Insert at front
        start = bucketLeft[lb];
        dqs[lb].insert(dqs[lb].begin() + (l - start), val);
        Maps[lb][val] ++;

        //Middle part
        for (int b = lb; b < rb; ++ b) {
            val = dqs[b].back();
            dqs[b].pop_back();
            Maps[b][val] --;

            dqs[b + 1].push_front(val);
            Maps[b + 1][val] ++;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];

    precompute();

    cin >> Q;

    int lastAns = 0;
    while (Q --) {
        int type, l, r;
        cin >> type >> l >> r;

        l = (l + lastAns - 1) % N + 1;
        r = (r + lastAns - 1) % N + 1;
        if (r < l)
            swap(l, r);

        if (type == 1)
            shift(l, r);
        else {
            int k;
            cin >> k;
            k = (k + lastAns - 1) % N + 1;

            lastAns = count(k, l, r);
            cout << lastAns << '\n';
        }
    }

    return 0;
}