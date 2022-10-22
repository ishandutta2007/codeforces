#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int maxN = 1005;

map <string, int> scorerId;

int numScores;

vector < pair <int, int> > events;
string names[maxN];
int scores[maxN];
int finalScores[maxN];

int main()
{
	int N;
	scanf ("%i", &N);

	for (int i = 0; i < N; i++)
	{
		char name[256];
		int x;
		scanf ("%s %i", name, &x);

		if (!scorerId[name])
		{
			names[numScores] = name;
			scorerId[name] = ++numScores;
		}

		scores[scorerId[name] - 1] += x;

		events.push_back (make_pair (scorerId[name] - 1, x));
	}

	int maxId = 0;
	for (int i = 0; i < numScores; i++)
		if (scores[i] > scores[maxId])
			maxId = i;

	int maxScore = scores[maxId];

	for (int i = 0; i < numScores; i++)
	{
		finalScores[i] = scores[i];
		scores[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		scores[events[i].first] += events[i].second;

		if (finalScores[events[i].first] == maxScore && scores[events[i].first] >= maxScore)
		{
			printf ("%s\n", names[events[i].first].c_str());
			return 0;
		}
	}

	return 0;
}