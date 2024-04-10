uses math;
var
  a:array[1..7]of longint;
  n,ans:longint;
  i,h:longint;
begin
  read(n);
  ans:=0;
  h:=0;
  for i:=1 to 7 do
    read(a[i]);

  repeat
    for i:=1 to 7 do
      begin
        dec(n,a[i]);
        inc(ans);
        if n<=0 then begin h:=1; break; end;
      end;
    if h=1 then break;
  until n<=0;
  if ans mod 7=0 then begin writeln(7); halt; end;
  writeln(ans mod 7);
end.