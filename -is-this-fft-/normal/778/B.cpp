#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAX_N = 5005;

struct Expr {
  int type; // <1 if numeric, 2 if expression>
  string val;

  int lft, rgt;
  char op;
};

Expr exprs [MAX_N];

bool vals [MAX_N];
int eval (int bit, int q, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (exprs[i].type == 1) {
      vals[i] = exprs[i].val[bit] - '0';
    } else {
      int lftv = exprs[i].lft == -1 ? q : vals[exprs[i].lft];
      int rgtv = exprs[i].rgt == -1 ? q : vals[exprs[i].rgt];

      if (exprs[i].op == '^') {
        vals[i] = lftv ^ rgtv;
      } else if (exprs[i].op == '|') {
        vals[i] = lftv | rgtv;
      } else {
        vals[i] = lftv & rgtv;
      }
    }
    ans += vals[i];
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  map<string, int> ids;
  ids[string("?")] = -1;
  for (int i = 0; i < n; i++) {
    string name, trash, fst;
    cin >> name >> trash >> fst;
    ids[name] = i;
    
    if (fst[0] == '0' || fst[0] == '1') {
      exprs[i].type = 1;
      exprs[i].val = fst;
    } else {
      string op, snd;
      cin >> op >> snd;

      exprs[i].type = 2;
      exprs[i].lft = ids[fst];
      exprs[i].rgt = ids[snd];

      if (op[0] == 'A') exprs[i].op = '&';
      else if (op[0] == 'X') exprs[i].op = '^';
      else exprs[i].op = '|';
    }
  }

  string ansmn, ansmx;
  for (int i = 0; i < m; i++) {
    int zv = eval(i, 0, n);
    int ov = eval(i, 1, n);

    if (zv < ov) {
      ansmn.push_back('0');
      ansmx.push_back('1');
    } else if (zv > ov) {
      ansmn.push_back('1');
      ansmx.push_back('0');      
    } else {
      ansmn.push_back('0');
      ansmx.push_back('0');
    }
  }

  cout << ansmn << endl << ansmx << endl;
}