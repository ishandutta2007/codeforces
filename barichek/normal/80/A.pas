uses math;
function fun(n:longint):boolean;
  var
    i:longint;
  begin
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then begin fun:=false; exit; end;
    fun:=true;
  end;
var
  n,m:longint;
  i:longint;
begin
  read(n,m);
  for i:=n+1 to m-1 do
    if fun(i) then begin writeln('NO'); halt; end;
  if fun(m) then writeln('YES')
  else writeln('NO');
end.