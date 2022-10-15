Program arsijo;
uses math;
Var a, b, c, i: longint;
Begin
   Read(a, b);
   c := b + 1;
   Write(c, ' ');
   for i:=1 to a do
       Write(c + i, ' ');
   for i:=1 to b do
       Write(c - i, ' ');
  
End.