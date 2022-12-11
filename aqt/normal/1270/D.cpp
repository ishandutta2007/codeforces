#include <bits/stdc++.h>

using namespace std;

unordered_set<int> st;
unordered_set<int> temp;
unordered_set<int> a, b;
int arr[505];
vector<int> v;

pair<int, int> query(){
    cout << "? ";
    for(int n : st){
        cout << n << " ";
    }
    cout << endl;
    pair<int, int> ret;
    cin >> ret.first >> ret.second;
    return ret;
}

int out(int n){
    cout << "! " << n << endl;
    exit(0);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    /*
    if(N >= 2*K-1){
        for(int i = 1; i<K; i++){
            st.insert(i);
        }
        for(int i = K; i<=2*K-1; i++){
            st.insert(i);
            pair<int, int> p = query();
            v.push_back(p.second);
            temp.insert(p.first);
            st.erase(p.first);
        }
        sort(v.begin(), v.end());
        swap(temp, st);
        pair<int, int> p = query();
        for(int k = 0; k<v.size(); k++){
            if(p.second == v[k]){
                out(k+1);
            }
        }
        return 0;
    }
    */
    for(int i = 1; i<=K; i++){
        st.insert(i);
    }
    fill(arr+1, arr+1+N, -1);
    auto p = query();
    arr[p.first] = p.second;
    int idx = p.first;
    st.insert(K+1);
    a.insert(K+1);
    bool ina = 1;
    for(int i = 1; i<=K; i++){
        if(i != idx){
            st.erase(i);
            auto q = query();
            arr[q.first] = q.second;
            if(q != p){
                if(ina){
                    ina = 0;
                }
                else{
                    ina = 1;
                }
            }
            if(ina){
                a.insert(i);
            }
            else{
                b.insert(i);
            }
            swap(p, q);
            st.insert(i);
        }
    }
    st.erase(idx);
    p = query();
    arr[p.first] = p.second;
    bool sw = 0;
    for(int n : a){
        if(arr[n]+1){
            if(arr[n] > arr[idx]){
                sw = 1;
            }
            break;
        }
    }
    if(sw){
        swap(a, b);
    }
    int cnt = 1;
    for(int n : a){
        if(n != K+1){
            cnt++;
        }
    }
    out(cnt);
}