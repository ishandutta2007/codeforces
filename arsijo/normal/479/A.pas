Program arsijo;
uses math;
var a, b, c, n, m: int64;
Begin
    Read(a, b, c);
    WriteLn(max(   max(a * b + c, a + b * c), max(  max(a + b + c, a * b * c), max((a + b) * c, a * (b + c)))));
    {
     a * b + c
     a + b * c
     a + b + c
     a * b * c
     (a + b) * c
     a * (b + c)
    }
End.