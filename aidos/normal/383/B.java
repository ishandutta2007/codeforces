import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {

	public static void main(String[] args) {
		new SolutionB().run();
	}

	int n;
	int m;

	void solve() {
		ArrayList <Pair> arr = new ArrayList<Pair>();
		TreeSet<Integer> ts = new TreeSet<Integer>();
		TreeSet <Pair> tsp = new TreeSet<Pair>();
		TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();
		n = in.nextInt();
		m = in.nextInt();
		tsp.add(new Pair(1, n+1));
		tsp.add(new Pair(n, n+1));
		for(int i = 0; i < m; i++){
			Pair x = new Pair(in.nextInt(), in.nextInt());
			tsp.add(x);
			if(x.x < n) tsp.add(new Pair(x.x+1, n+1));
			tsp.add(new Pair(x.x, n+1));
		}
		for(Pair t: tsp){
			arr.add(t);
			ts.add(t.y);
			if(t.y <= n) ts.add(t.y + 1);
			ts.add(t.y-1);
		}
		ts.add(0);
		ts.add(1);
		ts.add(n);
		m = arr.size();
		/*
		for(int i = 0; i < m; i++){
			Pair p = arr.get(i);
			//out.println(p.x + " " + p.y);
		}*/
		
		int cnt = 0;
		for(int k: ts){
			tm.put(k, cnt);
			//out.println("ts :" + k + " " + cnt);
			cnt++;
		}
		
		SegmentTree sg = new SegmentTree(0, cnt-1);
		sg.upd(1, 1, true);
		for(int i = 0; i < m; ){
			/*for(int t = 0; t<cnt; t++){
				if(sg.getNext(t, t) == -1){
					out.print("false ");
				}
				else out.print("true ");
			}
			out.println();*/
			int j = i;
			while(i < m && arr.get(j).x == arr.get(i).x) i++;
			//out.println(arr.get(j).x);
			ArrayList<Integer> ax  = new ArrayList<Integer>();
			while(j < i){
				ax.add(tm.get(arr.get(j).y));
				j++;
			}
			Collections.sort(ax);
			int from = 0;
			for(int x: ax){
				//out.print(x + " ");
				int nexti = -1;
				if(from+1 < x) nexti = sg.getNext(from+1, x-1);
				if(nexti == -1){
					sg.upd(from+1, x, false);
				}
				else {
					if(from+1 < nexti) sg.upd(from+1, nexti-1, false);
					sg.upd(nexti, x-1, true);
					sg.upd(x, x, false);
				}
				from = x;
			}
			//out.println();
		}
		
		if(sg.getNext(cnt-2, cnt-2) != -1) out.println((2 * n - 2));
		else out.println(-1);
	}

	class Pair implements Comparable<Pair> {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (o.x == x)
				return ((Integer) y).compareTo(o.y);
			return ((Integer) x).compareTo(o.x);
		}

	}
	class SegmentTree{
		SegmentTree left, right;
		int lx, rx;
		int nexti;
		boolean mustupd;
		boolean upd;
		public SegmentTree(int l, int r) {
			lx = l;
			rx = r;
			mustupd = false;
			upd = false;
			nexti = -1;
			if(l != r){
				int mid = (l + r) >> 1;
				left = new SegmentTree(l, mid);
				right = new SegmentTree(mid+1, r);
			}
		}
		void upd(int l, int r, boolean up){
			if(l ==lx && r == rx){
				mustupd = true;
				upd = up;
				if(up) nexti = l;
				else nexti = -1;
				return;
			}
			int mid = (lx + rx) >> 1;
			if(mustupd){
				left.upd = upd;
				left.mustupd = true;
				if(left.upd) left.nexti = left.lx;
				else left.nexti = -1;
				right.upd = upd;
				right.mustupd = true;
				if(right.upd) right.nexti = right.lx;
				else right.nexti = -1;
				mustupd = false;
			}
			if(mid >= r){
				left.upd(l, r, up);
			}
			else if(mid < l){
				right.upd(l, r, up);
			}
			else{
				left.upd(l, mid, up);
				right.upd(mid+1, r, up);
			}
			if(left.nexti != -1) nexti = left.nexti;
			else if(right.nexti != -1) nexti = right.nexti;
			else nexti = -1;
		}
		int getNext(int l, int r){
			if(lx == l && r == rx) return nexti;
			if(mustupd){
				left.upd = upd;
				left.mustupd = true;
				if(left.upd) left.nexti = left.lx;
				else left.nexti = -1;
				right.upd = upd;
				right.mustupd = true;
				if(right.upd) right.nexti = right.lx;
				else right.nexti = -1;
				mustupd = false;
			}
			int mid = (lx + rx) >> 1;
			if(mid >= r){
				return left.getNext(l, r);
			}
			else if(mid < l){
				return right.getNext(l, r);
			}
			else {
				int ansl = left.getNext(l, mid);
				int ansr = right.getNext(mid+1, r);
				if(ansl != -1) return ansl;
				return ansr;
			}
		}
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(new OutputStreamWriter(System.out));
		solve();
		out.close();
	}

	void runIO() {
		try {
			in = new FastScanner(new File("expr.in"));
			out = new PrintWriter(new FileWriter(new File("expr.out")));
			solve();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader bf;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				bf = new BufferedReader(new FileReader(f));
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

		public FastScanner(InputStream is) {
			bf = new BufferedReader(new InputStreamReader(is), 32768);
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(bf.readLine());
				} catch (IOException ex) {
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		String nextLine() {
			try {
				return bf.readLine();
			} catch (Exception ex) {
				ex.printStackTrace();
			}
			return "";
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(next());
		}

		BigDecimal nextBigDecimal() {
			return new BigDecimal(next());
		}

		int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = Integer.parseInt(next());
			return a;
		}

		long[] nextLongArray(int n) {
			long a[] = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = Long.parseLong(next());
			return a;
		}
	}
}