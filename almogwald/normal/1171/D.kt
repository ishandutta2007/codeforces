fun main(args: Array<String>) {
    val (x, y, z) = readLine()!!.split(' ').map(String::toLong)
    val (a, b, c) = readLine()!!.split(' ').map(String::toLong)
    if(x<= a && x+y<=a + b && x+y+z<=a+b+c){
        println("YES")
    }else{
        println("NO")
    }
}