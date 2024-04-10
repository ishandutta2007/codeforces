#include <bits/stdc++.h>

using namespace std;

int used[4000005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    unordered_set < int > Q;
    for (int i = 0; i <= 22; ++i) Q.insert((1<<i) - 1);
    vector < int > st;
    st.push_back(x);
    vector < int > pred;
    pred.push_back(-1);
    if (Q.find(x) != Q.end()){
        cout << 0 << '\n';
        return 0;
    }
    int head = 0, y;
    used[x] = 1;
    while (head < (int)st.size()){
        x = st[head];
        head++;
        for (int i = 0; i <= 21; ++i){
            y = (1<<i) - 1;
            if ((x^y) + 1 <= 4000000 && used[(x^y) + 1] == 0){
                used[(x^y) + 1] = 1;
                st.push_back((x^y) + 1);
                pred.push_back(head - 1);
                if (Q.find(st.back()) != Q.end()){
                    int my_pos = (int)pred.size() - 1;
                    vector < int > ans;
                    while (my_pos != 0){
                        int to = pred[my_pos];
                        for (int i = 0; i <= 21; ++i){
                            y = (1<<i) - 1;
                            if ((st[to]^y) + 1 == st[my_pos]){
                                ans.push_back(i);
                                break;
                            }
                        }
                        my_pos = to;
                    }
                    cout << (int)ans.size() * 2 << '\n';
                    for (int i = (int)ans.size() - 1; i >= 0; --i) cout << ans[i] << " ";
                    return 0;
                }
            }
        }
    }
    return 0;
}