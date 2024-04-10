//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

vector<int> it[200001];
struct custom_hash {
    typedef long long ll;
    typedef unsigned long long ull;
    const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(const pair<int,int> &i)const{
        return splitmix64((((ll)i.first)^(((ll)i.second)<<32))+FIXED_RANDOM);
    }
};
vector<int> ss[200002];
int vis[200002];
//int vis3[200002];
using namespace std::chrono; 
vector<pair<int,int>> dis[200001];
//int  gg[200002][200002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			it[i].clear();
		}

		//map<int,vector<int>> ss;
		set<int> kk;
	//	map<int,int> cd;
		map<int,int> de;
		 auto start = high_resolution_clock::now(); 


		int cot=0;
		map<int,int> pc3;
		for(int i=0;i<n;i++){
			int cc;
			cin>>cc;
			cot+=cc;
			//set<int> pc2;
			for(int j=0;j<cc;j++){
				int dd;
				cin>>dd;
			//	pc2.insert(dd);
				it[i].pb(dd);
				kk.insert(dd);
				//ss[dd].pb(i);
			}
			for(auto j:it[i]){
				pc3[j]++;
			}
			sort(it[i].begin(),it[i].end());

		}
		for(int i=0;i<cot;i++){
			dis[i].clear();
		}
	/*	for(int i=0;i<n;i++){
			vis3[i]=0;
		}*/
		int co=0;
		for(auto j:pc3){
			if(j.b>=2){
				co+=1;
			}
		}
		if(co<2){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<kk.size();i++){
			ss[i].clear();
		}
		//i
		/*if(kk.size()>cot-2){
			cout<<-1<<endl;
			continue;
		}*/
		int pc=0;
		for(auto j:kk){
			//cd[pc]=j;
			de[j]=pc;
			pc++;
		}

		for(int i=0;i<n;i++){
			/*int cot=-1;
			int st=0;
			for(auto j:it[i]){
				if(pc3[j]>=2){
					if(cot!=j){
						st=1;
					}
					cot=j;
				}
				if(cot==2){
					break;
				}
			}
			if(st==0){

			}*/
			vector<int> mp;

			//int ind2=0;
			for(int j=0;j<it[i].size();j++){
				if(pc3[it[i][j]]<2){
					continue;
				}

			//	it[i][ind2]=de[it[i][j]];
				//ind2++;
				mp.pb(de[it[i][j]]);
				ss[de[it[i][j]]].pb(i);
			}
			it[i].clear();
			for(auto j:mp){
				it[i].pb(j);
			}
		}
		pair<int,int> ans={-1,-1};
		//map<pair<int,int>,int> tt;
	//	unordered_map<pair<int,int>,int,custom_hash> tt;
		vector<pair<int,int>> acc;
		int ac=400;
		for(int i=0;i<n;i++){
			if(it[i].size()<ac){
				for(int j=0;j<it[i].size();j++){
					for(int k=j+1;k<it[i].size();k++){
					//	acc.pb({})
						//cout<<it[i][j]<<":"<<it[i][k]<<":"<<i<<endl;
						dis[it[i][j]].pb({it[i][k],i});
					//	acc.pb({it[i][j]*200000+it[i][k],i});
						/*if(tt.find({it[i][j],it[i][k]})!=tt.end()){
							ans={tt[{it[i][j],it[i][k]}],i};
							break;
						}
						else{
							tt[{it[i][j],it[i][k]}]=i;
						}*/
					}
				/*	if(ans.a!=-1){
						break;
					}*/

				}
			}
			if(ans.a!=-1){
					break;
				}
			//	 auto stop = high_resolution_clock::now(); 
			//    auto duration = duration_cast<microseconds>(stop - start); 
			  /*  if(duration.count()>=450000){
			    	break;
			    }*/



		}
		for(int i=0;i<cot;i++){
		//	if(dis[i].size()){
				for(auto j:dis[i]){
					//cout<<j.a<<",,"<<j.b<<endl;
					if(vis[j.a]>0){
						ans={vis[j.a]-1,j.b};
						//cout<<vis[j.a]<<"::"<<j.a<<",,"<<j.b<<endl;
					}
					else{
						vis[j.a]=j.b;
						vis[j.a]+=1;
						//cout<<vis[j.a]<<endl;
					}
				}

				for(auto j:dis[i]){
					vis[j.a]=0;
				}
			//}
		}
		/*sort(acc.begin(),acc.end());
		for(int j=1;j<acc.size();j++){
			if(acc[j].a==acc[j-1].a){
				ans={acc[j].b,acc[j-1].b};
			}
		}*/
		vector<int> ec;

		for(int i=0;i<n;i++){
			//unordered_map<int,int,custom_hash> ee;
			
			if(it[i].size()>=ac){
				for(auto j:it[i]){
					for(auto k:ss[j]){
						if(k!=i){
							if(vis[k]){
								ans={i,k};

							}
							else{
								vis[k]=1;
								ec.pb(k);
							}
						}
					}
				}
				for(auto j:ec){
					vis[j]=0;
				}
				if(ans.a!=-1){
					break;
				}
				ec.clear();
				/* auto stop = high_resolution_clock::now(); 
			    auto duration = duration_cast<microseconds>(stop - start); 
			    if(duration.count()>=450000){
			    	break;
			    }*/
			}

		}
		if(ans.a==-1){
			cout<<-1<<endl;
		}
		else{
			cout<<ans.a+1<<" "<<ans.b+1<<endl;
		}


	}




 
	return 0;
}