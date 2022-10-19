#[allow(unused_imports)]
use std::io::*;
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

const MOD: i32 = (7*17 << 23) + 1;
type Graph = Vec<Vec<usize>>;

fn dfs(v: usize, vec: &mut Vec<usize>, g: &Graph, vis: &mut [bool])
{
    vis[v] = true;
    for &u in &g[v] {
        if !vis[u] {
            dfs(u, vec, g, vis);
        }
    }
    vec.push(v);
}

fn topo(g: &Graph) -> Vec<usize>
{
    let mut vis = vec![false; g.len()];
    let mut vec = vec![0usize; 0];
    for i in 0..g.len() {
        if !vis[i] {
            dfs(i, &mut vec, g, &mut vis);
        }
    }
    vec
}

fn weight(g: &Graph, topo: &[usize]) -> Vec<i32>
{
    let mut ans = vec![0; g.len()];
    ans[topo[0]] = 1;
    for &v in topo {
        for &u in &g[v] {
            ans[v] += ans[u];
            ans[v] %= MOD;
        }
    }
    ans
}

fn advance(g: &Graph, val: &mut [i32], topo: &[usize])
{
    for &v in topo {
        if val[v] == 0 {
            continue
        }
        val[v] -= 1;
        for &u in &g[v] {
            val[u] += 1;
        }
    }
}

fn solve(scan: &mut Scanner, out: &mut BufWriter<Stdout>)
{
    let (n, m): (usize, usize) = (scan.next(), scan.next());
    let mut val: Vec<i32> = (0..n).map(|_| scan.next()).collect();
    let mut g = vec![vec![]; n];
    for _ in 0..m {
        let (v, u): (usize, usize) = (scan.next(), scan.next());
        g[v - 1].push(u - 1);
    }
    let topo = topo(&g);
    for i in 0..n {
        //eprintln!("{:?}", val);
        if let None = val.iter().find(|&&x| x != 0) {
            writeln!(out, "{}", i).ok();
            return;
        }
        advance(&g, &mut val, &topo);
    }
    //eprintln!("{:?}", val);
    let weight = weight(&g, &topo);
    //eprintln!("{:?}", weight);
    let mut ans = n as i64;
    for x in 0..n {
        ans += (val[x] as i64) * (weight[x] as i64);
        ans %= MOD as i64;
    }
    writeln!(out, "{}", ans).ok();
}


fn main()
{
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let t: i32 = scan.next();
    for _ in 0..t {
        solve(&mut scan, &mut out);
    }
}