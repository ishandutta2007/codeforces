#include <bits/stdc++.h>
using namespace std;



pair<int,int> parent[1005];
int rank2[1005];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rank2[v] = 0;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

bool add_edge(int a, int b, bool dif) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if ((x != y) != dif )
            return false;
        else
            return true;
    } else {
        if (rank2[a] < rank2[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^dif );
        if (rank2[a] == rank2[b])
            ++rank2[a];
        return true;
    }
}

int arr[1005][1005];
int main(int argc,char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int ttt = 0; ttt < tc; ttt++  ){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                cin >> arr[i][j];
            }
        }
        for(int i= 0; i < n; i ++){
            make_set(i);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j ++){
                if(i >= j){
                    continue;
                }
                int first = arr[i][j];
                int second = arr[j][i];
                bool ok;
                if(first == second){
                    continue;
                }
                if(first < second){
                    ok = add_edge(i,j,false);
                }else{
                    ok = add_edge(i,j,true);
                }
                if(ok){
                    arr[i][j] = min(first,second);
                    arr[j][i] = max(first,second);
                }else{
                    arr[j][i] = min(first,second);
                    arr[i][j] = max(first,second);
                }

//                cout << i << " " << j << " " << ok << " " << "\n";
//                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

/*
 *
 *
1
 4
3 3 1 2
1 1 3 1
3 2 3 2
2 3 3 1

 */