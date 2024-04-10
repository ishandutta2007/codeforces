#include <bits/stdc++.h>

using namespace std;

const int N_ = 1005000;

int N;
int children[N_][2];
char type[N_];
int value[N_];

vector<int> *results[N_][2];

char tmp[10];

void merge(vector<int> *&a, vector<int> *&b) { // a <- b
  if(a->size() < b->size()) {
    swap(a, b);
  }
  // |a| > |b| -> b a 
  for(int x : *b) {
    a->push_back(x);
  }
  b->clear();
}

// : u    1   ,    
vector<int>** solve(int u) {
  #define ret results[u]
  ret[0] = new vector<int>();
  ret[1] = new vector<int>();
  vector<int>** rec, **recl, **recr;

  switch(type[u]) {
    case 'I':
      value[u] = children[u][0];
      ret[value[u]]->push_back(-1);
      ret[!value[u]]->push_back(u);
      break;
    case 'N':
      rec = solve(children[u][0]);
      value[u] = !value[children[u][0]];
      ret[0] = rec[1];
      ret[1] = rec[0];
      break;
    case 'A':
    case 'X':
    case 'O':
      recl = solve(children[u][0]);
      recr = solve(children[u][1]);

      if(type[u] == 'A') {
        value[u] = value[children[u][0]] & value[children[u][1]];
        merge(ret[value[children[u][1]] & 0], recl[0]);
        merge(ret[value[children[u][1]] & 1], recl[1]);
        merge(ret[value[children[u][0]] & 0], recr[0]);
        merge(ret[value[children[u][0]] & 1], recr[1]);
      }else if(type[u] == 'X') {
        value[u] = value[children[u][0]] ^ value[children[u][1]];
        merge(ret[value[children[u][1]] ^ 0], recl[0]);
        merge(ret[value[children[u][1]] ^ 1], recl[1]);
        merge(ret[value[children[u][0]] ^ 0], recr[0]);
        merge(ret[value[children[u][0]] ^ 1], recr[1]);
      }else {
        value[u] = value[children[u][0]] | value[children[u][1]];
        merge(ret[value[children[u][1]] | 0], recl[0]);
        merge(ret[value[children[u][1]] | 1], recl[1]);
        merge(ret[value[children[u][0]] | 0], recr[0]);
        merge(ret[value[children[u][0]] | 1], recr[1]);
      }
      break;
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%s", tmp); type[i] = *tmp;
    int c = (type[i] == 'I' || type[i] == 'N') ? 1 : 2;
    for(int j = 0; j < c; j++) scanf("%d", &children[i][j]);
  }

  solve(1);
  vector<int> answer(N);
  for(int i : *(results[1][1])) if(i > 0) answer[i-1] = 1;

  for(int i = 0; i < N; i++) {
    if(type[i+1] == 'I') putchar(answer[i] + '0');
  }
  puts("");
  return 0;
}