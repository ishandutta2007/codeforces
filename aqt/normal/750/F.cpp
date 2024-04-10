
// Problem : F. New Year and Finding Roots
// Contest : Codeforces - Good Bye 2016
// URL : https://codeforces.com/contest/750/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());
int T, H;
map<int, vector<int>> mp;
stack<int> stk;
vector<int> graph[200];
vector<int> cgraph[200];
int S;

vector<int> query(int n){
	if(mp.count(n)){
		return mp[n];
	}
	cout << "? " << n << endl;
	vector<int> ret;
    S++;

    assert(S < 17);

	int k;
	cin >> k;
	if(!k){
		exit(0);
	}
	while(k--){
		int nn;
		cin >> nn;
		if(!nn){
			exit(0);
		}
		ret.push_back(nn);
	}
	mp[n] = ret;

    /*
	ret = graph[n];
	sort(ret.begin(), ret.end());
	for(int e : ret){
	    if(n < e){
            cgraph[n].push_back(e);
	    }
	    else{
            cgraph[e].push_back(n);
	    }
        cout << e << " ";
	}
	cout << endl;
    */
	return mp[n] = ret;
}

int dfs(int n, bool b = 0){
	auto adj = query(n);
	if(adj.size() == 2){
		cout << "! " << n << endl;
		return INT_MIN/2;
	}
	int ret = 1;
	if(b){
		stk.push(n);
	}
	for(int e : adj){
		if(!mp.count(e)){
			ret += dfs(e, b);
			break;
		}
	}
	return ret;
}

void solve(){
	cin >> H;
	if(!H){
		exit(0);
	}
    /*
	for(int i = 1; i<(1<<H)-1; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
    */
	if(H <= 4){
		for(int i = 1; i<1<<4; i++){
			auto adj = query(i);
			if(adj.size() == 2){
				cout << "! " << i << endl;
				return;
			}
		}
	}
	int rt = 1;
	int crnt = rt, crnth, lst;
	auto adj = query(crnt);
	if(adj.size() == 2){
		cout << "! " << crnt << endl;
		return;
	}
	else if(adj.size() == 1){
		crnth = H-1;
        crnt = adj[0];
	}
	else {
		int opt1 = dfs(adj[0], 1);
		if(opt1 < 0){
			return;
		}
		int opt2 = dfs(adj[1], 1);
		if(opt2 < 0){
			return;
		}
		crnth = H - min(opt1, opt2);
		if(opt1 > opt2){
			int s = opt1 - H + crnth;
			int x = s/2 + H-crnth;
			for(int xx = 0; xx<x+opt2; xx++){
				stk.pop();
			}
			//cout << stk.top() << endl;
			crnth -= s/2;
			int temp = crnt;
			//assert(stk.size());
			crnt = stk.top();
			//stk.pop();
			//lst = stk.empty() ? temp : stk.top();
		}
		else if(opt1 < opt2){
			int s = opt2 - H + crnth;
			int x = s/2 + H-crnth;
			for(int xx = 0; xx<x; xx++){
				stk.pop();
			}
			//cout << stk.top() << endl;
			crnth -= s/2;
			int temp = crnt;
			//assert(stk.size());
			crnt = stk.top();
			//stk.pop();
			//assert(stk.size() > opt1);
			//lst = stk.size() == opt1 ? temp : stk.top();
		}
		crnth--;
		lst = crnt;
		adj = query(crnt);
		assert(adj.size() >= 2);
        int counting = 0;
        for(int e : adj){
            if(!mp.count(e)){
                crnt = e;
                counting++;
            }
        }
        assert(counting == 1);
	}
	while(stk.size()){
		stk.pop();
	}
	//cout << "start: " << crnt << " " << crnth << endl;
	//cout << "wtf: " << crnt << " " << crnth << endl;
	while(crnth > 3){
        //cout << "iteration: " << crnt << " " << crnth << endl;
		auto adj = query(crnt);
		for(int e : adj){
			if(!mp.count(e)){
                //assert(e != lst);
				int s = dfs(e, 1);
				if(s < 0){
					return;
				}
				s -= H-crnth;
				//cout << s << endl;
				if(s){
					assert(s%2 == 0 && s > 0);
					int x = s/2 + H-crnth;
					//cout << x << endl;
					for(int xx = 0; xx<x; xx++){
						stk.pop();
					}
					//cout << stk.top() << endl;
					crnth -= s/2;
					int temp = crnt;
					assert(stk.size());
					crnt = stk.top();
                    crnth--;
                    lst = crnt;
                    adj = query(crnt);
                    assert(adj.size() >= 2);
                    int counting = 0;
                    for(int e : adj){
                        if(!mp.count(e)){
                            crnt = e;
                            counting++;
                        }
                    }
                    assert(counting == 1);
				}
				else{
					int cntr = 0;
					for(int ee : adj){
						cntr++;
						if(!mp.count(ee)){
							crnth--;
							lst = crnt;
							crnt = ee;
							break;
						}
						assert(cntr != 3);
					}
				}
				while(stk.size()){
					stk.pop();
				}
				break;
			}
		}
	}
	//cout << "here" << " " << crnt << " " << crnth << " " << lst << endl;
	if(crnth == 3){
		int cnt = 0;
		auto adj = query(crnt);
		for(int e : adj){
			if(e != lst){
				cnt++;
				auto adje = query(e);
				assert(adje.size() == 3);
				int cntr = 0;
				for(int ee : adje){
					if(ee == crnt){
						continue;
					}
					cntr++;
					assert(cntr != 3);
					if(cnt == 1){
						if(query(ee).size() == 2){
							cout << "! " << ee << endl;
							return;
						}
					}
					else if(cnt == 2){
						cnt++;
						if(query(ee).size() == 2){
							cout << "! " << ee << endl;
							return;
						}
					}
					else{
                        //assert(0);
						cout << "! " << ee << endl;
						return;
					}
				}
			}
		}
	}
	else if(crnth == 2){
        auto adj = query(crnt);
		for(int e : adj){
			if(e != lst){
				if(query(e).size() == 2){
					cout << "! " << e << endl;
					return ;
				}
			}
		}
	}
	else if(crnth == 1){
        cout << "! " << crnt << endl;
        return ;
	}

	assert(crnth != 2);

    assert(crnth != 3);

	assert(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		solve();
		mp.clear();
		while(stk.size()){
			stk.pop();
		}
		/*
		for(int i = 1; i<200; i++){
            if(graph[i].size() == 2){
                cout << i << endl;
            }
            sort(cgraph[i].begin(), cgraph[i].end());
            cgraph[i].erase(unique(cgraph[i].begin(), cgraph[i].end()), cgraph[i].end());
            for(int e : cgraph[i]){
                cout << e << " " << i << endl;
            }
		}
		for(int i = 1; i<200; i++){
            graph[i].clear();
		}
		*/
		S = 0;
	}
}