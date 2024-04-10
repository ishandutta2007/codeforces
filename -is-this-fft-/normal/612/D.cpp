#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main () {
  int segmentc, param;
  scanf("%d %d", &segmentc, &param);

  vector<pair<int, int> > segments (segmentc);
  vector<int> coords (segmentc * 2);
  for (int i = 0; i < segmentc; i++) {
    scanf("%d %d", &segments[i].first, &segments[i].second);
    coords[i * 2] = segments[i].first;
    coords[i * 2 + 1] = segments[i].second;
  }

  sort(coords.begin(), coords.end());
  
  map<int, int> smallval;
  vector<int> bigval (0);
  for (int i = 0; i < coords.size(); i++) {
    if (i == 0 || coords[i] > coords[i - 1]) {
      smallval[coords[i]] = bigval.size();
      bigval.push_back(coords[i]);
    }
  }

  vector<int> prefix (bigval.size() * 2, 0);
  for (int i = 0; i < segments.size(); i++) {
    prefix[smallval[segments[i].first] * 2]++;
    prefix[smallval[segments[i].second] * 2 + 1]--;
  }

  for (int i = 1; i < prefix.size(); i++) {
    prefix[i] += prefix[i - 1];
  }

  vector<pair<int, int> > ans (0);
  int cstart = -1;
  for (int i = 0; i < prefix.size(); i++) {
    if (cstart == -1 && prefix[i] >= param) {
      cstart = i;
    } else if (cstart != -1 && prefix[i] < param) {
      ans.push_back(make_pair(cstart / 2, i / 2));
      cstart = -1;
    }
  }

  printf("%d\n", (int) ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", bigval[ans[i].first], bigval[ans[i].second]);
  }
}