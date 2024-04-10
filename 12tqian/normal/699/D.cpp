#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
static vector<vector<int>> adj;
static vector<vector<int>> dadj;
static int p [MAX];
static int ans [MAX];
static int vis[MAX];
static int vis1[MAX];
int cycles(int src){
    int fin = -1;
    list<int> q;
    vis[src] = 1;
    q.emplace_back(src);
    while(!q.empty()){
        int s = q.front();
        q.pop_front();
        for(int n: dadj[s]){
            if(vis[n] == 1){
                fin = n;
            }
            if(vis[n] == 0){
                vis[n] = 1;
                q.emplace_back(n);
            }
        }
    }
    return fin;
}
void bfs(int src){
    list<int> q;
    vis1[src] = 1;
    q.emplace_back(src);
    while(!q.empty()){
        int s = q.front();
        q.pop_front();
        for(int n: adj[s]){
            if(vis1[n] == 0){
                vis1[n] = 1;
                q.emplace_back(n);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int c = 0;
    for(int i = 0; i<n; i++){
        vector<int> temp;
        adj.emplace_back(temp);
        dadj.emplace_back(temp);
    }
    vector<int> trees;
    int root = -1;
    for(int i = 0; i<n; i++){
        int d;
        scanf("%d", &d);
        d -= 1;
        dadj[i].emplace_back(d);
      //  cout << "asdfdasF" << endl;
        adj[i].emplace_back(d);
       // cout<< "oh" << endl;
        adj[d].emplace_back(i);
       // cout <<"sad" << endl;
        p[i] = d;
        ans[i] = d;
        if(i == d && root!= -1){
            ans[i] = root;
            trees.emplace_back(d);
            c += 1;
         //   cout<< "number 1" <<endl;
        }
        if(root == -1 && i == d){
            root = d;
            trees.emplace_back(root);
        }
    }
    for(int i = 0; i<n; i++){
        if(vis1[i] == 0){
                //cout << "here" << endl;
            int x = cycles(i);
            bfs(i);
            if(x != -1 && root == -1){
                ans[x] = x;
                c += 1;
                root = x;
               // cout << "number 2" << endl;
            }
            if(x!= -1 && root != -1){
                //cout << "number 3" <<endl;
                if(ans[x] == root){
                    continue;
                }
                ans[x] = root;
                c += 1;
            }
        }
    }
 //   cout << root << " root" << endl;
    cout << c << endl;
    for(int i = 0; i<n; i++){
        cout << ans[i] + 1 << " ";
    }
    return 0;
}