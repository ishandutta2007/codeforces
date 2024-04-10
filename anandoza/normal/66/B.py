n = int(raw_input())
heights = tuple(int(i) for i in raw_input().split())

def flood(heights):
  decr = [heights[i+1] <= heights[i] for i in range(len(heights) - 1)] + [False]
  return decr.index(False)
  
print max(1 + flood(heights[i:]) + flood(heights[:i+1][::-1]) for i in range(n))