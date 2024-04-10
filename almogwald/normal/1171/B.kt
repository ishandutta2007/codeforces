fun main(args: Array<String>) {
    var (n, m, k) = readLine()!!.split(' ').map(String::toLong)
    if(n+1<m){
        m=n+1
    }
    if(k-1<m){
        m=k-1
    } 
    println(3*m)
}