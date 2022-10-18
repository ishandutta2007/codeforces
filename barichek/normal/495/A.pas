uses math;
var
  n,a,b:longint;
begin
  read(n);
  a:=n div 10;
  b:=n mod 10;
  case a of
    0: a:=2;
    1: a:=7;
    2: a:=2;
    3: a:=3;
    4: a:=3;
    5: a:=4;
    6: a:=2;
    7: a:=5;
    8: a:=1;
    9: a:=2;
  end;
  case b of
    0: b:=2;
    1: b:=7;
    2: b:=2;
    3: b:=3;
    4: b:=3;
    5: b:=4;
    6: b:=2;
    7: b:=5;
    8: b:=1;
    9: b:=2;
  end;

  writeln(a*b);
end.