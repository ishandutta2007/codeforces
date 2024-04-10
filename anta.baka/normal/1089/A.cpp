#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vll = vector<ll>;

const int inf = 1e9+100;
const int nax = 500;

vector<pii> cou[4][4];
vector<vector<pii>> best(201, vector<pii>(201, mp(-inf, inf)));
vector<vector<vector<pii>>> vans(201, vector<vector<pii>>(201));

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    for(int len = 3; len <= 5; len++) {
        for(int mask = 0; mask < (1 << (2 * len)); mask++) {
            vi what(len);
            int tmp = mask;
            for(int i = 0; i < len; i++) {
                what[i] = tmp % 4;
                tmp /= 4;
            }
            int w1 = 0, w2 = 0;
            bool good = true;
            for(int i = 0; i < len; i++) {
                if(what[i] == 0 || what[i] == 2) w1++;
                else w2++;
                if(abs(max(w1, w2)) == 3 && i != len - 1) good = false;
            }
            if(max(w1, w2) < 3) continue;
            if(!good) continue;
            int A = 0, B = 0;
            int canaddA = 0, canaddB = 0;
            vector<pii> vec(len, mp(0, 0));
            bool canone = false;
            int idone = -1;
            for(int i = 0; i < len; i++) {
                if(what[i] == 0) {
                    if(i == 4) A += 15, canaddB += 13, vec[i].fi = 15;
                    else A += 25, canaddB += 23, vec[i].fi = 25;
                } else if(what[i] == 1) {
                    if(i == 4) B += 15, canaddA += 13, vec[i].se = 15;
                    else B += 25, canaddA += 23, vec[i].se = 25;
                } else if(what[i] == 2) {
                    A += 26, B += 24, canone = true, idone = i;
                    vec[i] = mp(26, 24);
                } else if(what[i] == 3) {
                    A += 24, B += 26, canone = true, idone = i;
                    vec[i] = mp(24, 26);
                }
            }
            for(int adda = 0; adda <= canaddA && A + adda <= 200; adda++) {
                for(int addb = 0; addb <= canaddB && B + addb <= 200; addb++) {
                    int nA = A + adda, nB = B + addb;
                    vector<pii> vec1 = vec;
                    int needa = adda, needb = addb;
                    for(int i = 0; i < len; i++) {
                        if(what[i] == 0) {
                            if(i != 4) {
                                int can = min(23, needb);
                                vec1[i].se += can;
                                needb -= can;
                            } else {
                                int can = min(13, needb);
                                vec1[i].se += can;
                                needb -= can;
                            }
                        } else if(what[i] == 1) {
                            if(i != 4) {
                                int can = min(23, needa);
                                vec1[i].fi += can;
                                needa -= can;
                            } else {
                                int can = min(13, needa);
                                vec1[i].fi += can;
                                needa -= can;
                            }
                        }
                    }
                    //assert(needa == 0 && needb == 0);
                    if(w1 - w2 > best[nA][nB].fi - best[nA][nB].se || w1 - w2 == best[nA][nB].fi - best[nA][nB].se && w1 > best[nA][nB].fi) {
                        best[nA][nB] = mp(w1, w2);
                        vans[nA][nB] = vec1;
                    }
                    if(canone) {
                        while(nA + 1 <= 200 && nB + 1 <= 200) {
                            nA++; nB++;
                            vec1[idone].fi++;
                            vec1[idone].se++;
                            if(w1 - w2 > best[nA][nB].fi - best[nA][nB].se || w1 - w2 == best[nA][nB].fi - best[nA][nB].se && w1 > best[nA][nB].fi) {
                                best[nA][nB] = mp(w1, w2);
                                vans[nA][nB] = vec1;
                            }
                        }
                    }
                }
            }
        }
    }
    int q; cin >> q;
    while(q--) {
        int A, B; cin >> A >> B;
        if(best[A][B] == mp(-inf, inf)) {
            cout << "Impossible\n";
        } else {
            cout << best[A][B].fi << ':' << best[A][B].se << '\n';
            for(pii x : vans[A][B]) cout << x.fi << ':' << x.se << ' ';
            cout << '\n';
        }
    }
}