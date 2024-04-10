uses math;
var
  a:array[1..100000]of longint;
  kn,kp,n:int64;
  i:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  kp:=0;
  kn:=0;

  for i:=1 to n do
    if a[i] mod 2=1 then inc(kn)
    else inc(kp);

  for i:=1 to n do
    begin
      if (a[i] mod 2=0) and (kp=1) then writeln(i);
      if (a[i] mod 2=1) and (kn=1) then writeln(i);
    end;
end.