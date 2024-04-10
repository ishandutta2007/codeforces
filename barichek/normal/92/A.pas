uses math;
var
  n,m:longint;
  i:longint;
begin
  read(n,m);
  repeat
    for i:=1 to n do
      begin
        dec(m,i);
        if m<0 then begin writeln(m+i); halt; end;
      end;
  until m<0;
end.