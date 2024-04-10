uses math;
Var a: array [1..1000000] of longint;
    n, m, i, x: longint;
Begin
  readln(n);
  for i:=1 to n do
  begin
    Read(x);
    while x > 0 do
    begin
      inc(m);
      dec(x);
      a[m]:=i;
    end;
  end;
  ReadLn(m);
  for i:=1 to m do
  begin
    Read(x);
    WriteLn(a[x]);
  end;
End.