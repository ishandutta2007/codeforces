#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
const int ALF = 26;

int n;
int cnt[ALF];
int cnt2[ALF];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &cnt[i]);
}

void solve() {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += cnt[i];
    //int t = 0;
    string res;
    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < cnt[i]; j++)
            res += 'a' + i;

   
    if (sum % 2 == 1)  {

        int id = -1;
        for (int i = 0; i < n; i++)
            if (cnt[i] % 2 == 1)
                id = i;

        for (int t = 1; t <= sum; t++) {
            bool flag = 1;
            flag &= cnt[id] >= t;
            for (int i = 0; i < n; i++) {
                cnt2[i] = cnt[i] / t;
                flag &= cnt[i] % t == 0;
            }
            cnt2[id]--;
            int odd = 0;
            for (int i = 0; i < n; i++)
                odd += cnt2[i] % 2;
            flag &= odd <= 1;

            if (!flag) continue;
        
            string g;
            for (int i = 0; i < n; i++)
                for (; cnt2[i] > 1; cnt2[i] -= 2)
                    g += i + 'a';
            string gr = g;
            reverse(gr.begin(), gr.end());
            for (int i = 0; i < n; i++)
                if (cnt2[i])
                    g += i + 'a';
            g += gr + (char)(id + 'a');
            res = "";
            for (int i = 0; i < t; i++) {
                res += g;
            }
            answer = t;
        }
    }
    else {
        for (int t = 2; t <= sum; t += 2) {
            //db2(sum, t)
            if (sum % t != 0) continue;
            //db(t);
            //int sz = sum / t;
            bool flag = 1; 
            for (int i = 0; i < n; i++) {
                flag &= (cnt[i] % t) == 0;
                cnt2[i] = cnt[i] / t;
            }
            if (!flag) continue;
           
            string tmp; 
            for (int i = 0; i < n; i++)
                for (; cnt2[i] > 0; cnt2[i]--)
                    tmp += 'a' + i; 
            string tmpr = tmp;
            reverse(tmpr.begin(), tmpr.end());
            //db(block.size());
            res = "";
            for (int i = 0; i < t; i++)
                if (i % 2 == 0)
                    res += tmp;
                else
                    res += tmpr;
            answer = t;
        }

    }


    //for (int t = 1; ; t++) {
        //bool flag = 1; 
        //int odd = 0;
        //for (int i = 0; i < n; i++) {
            //flag &= (cnt[i] % (1 << t)) == 0;
            //cnt2[i] = cnt[i] >> t;
            //odd += cnt2[i] % 2;
        //}
        //if (!flag) break;
       
        //string tmp; 
        //for (int i = 0; i < n; i++)
            //for (; cnt2[i] > 0; cnt2[i]--)
                //tmp += 'a' + i; 
        //string tmpr = tmp;
        //reverse(tmpr.begin(), tmpr.end());
        ////db(block.size());
        //res = "";
        //for (int i = 0; i < (1 << t); i++)
            //if (i % 2 == 0)
                //res += tmp;
            //else
                //res += tmpr;
        //answer = (1 << t);
    //}


    cout << answer << endl;
    cout << res << endl;


}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}