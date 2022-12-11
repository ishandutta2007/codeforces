#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

struct Inter {
   int pos, val;
};

bool operator < (const Inter& a, const Inter& b) {
   return a.val < b.val;
}

int nombres[100 * 1000];
int positions[100 * 1000];

priority_queue<Inter> tries;
set<int> inters;

void ajoute(int pos) {
   inters.erase(pos);

   auto it = inters.lower_bound(pos);
   auto bef = it; bef--;
   
   if(it != inters.end()) {
      tries.push({*it, *it - *bef});
   }
}

int getVal(int pos) {
   auto it = inters.lower_bound(pos);
   
   if(it == inters.end() || *it != pos) {
      return -1;
   }
   
   it--;
   return pos - *it;
}

void solve() {
   int taille;
   cin >> taille;
   
   while(!tries.empty()) tries.pop();
   inters.clear();
   
   inters.insert(-1);
   
   for(int i = 0;i < taille;i++) {
      cin >> nombres[i];
      nombres[i]--;
      positions[nombres[i]] = i;
      
      inters.insert(i);
      tries.push({i, 1});
   }
   
   for(int i = 0;i < taille;i++) {
      while(getVal(tries.top().pos) != tries.top().val) {
         tries.pop();
      }
      
      if(tries.empty()) {
         cout << "No" << endl;
         return;
      }
      
      int taille = getVal(positions[i]);
      
      if(taille != tries.top().val) {
         cout << "No" << endl;
         return;
      }
      
      ajoute(positions[i]);
   }
   
   cout << "Yes" << endl;
}

signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int nbTests;
   cin >> nbTests;
   
   for(int iTest = 0;iTest < nbTests;iTest++) {
      solve();
   }
   return 0;
}