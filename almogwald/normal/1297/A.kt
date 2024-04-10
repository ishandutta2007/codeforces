fun foo(){
    var n = readLine()!!.toInt() 
    if (n<1000) {
        println(n)
    } else {
      var a = (n+500)/1000
      if (a<1000) {
        print(a)
        println("K")
      } else {
          n = (n+500000)/1000000
          print(n)
          println("M")
      }          
    }
}
 
fun main(args: Array<String>) {
    var n = readLine()!!.toInt() 
    for (i in 1..n) {
        foo()
    }
}