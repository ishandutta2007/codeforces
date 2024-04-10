fun main(args:Array<String>) {
    val (a, b, c) = readLine()!!.split(' ').map(String::toInt)
    if (b < a && c < a && b > 0 && c > 0)
  {
    println(0)
    return
  }
  if ((b == a || b == 0) && c >= 0 && c <= a)
  {
    println(1)
    return
  }
  if ((c == a || c == 0) && (b >= 0 && b <= a))
  {
    println(1)
    return
  }
  println(2)
}