uses math;
var
  s:string;
  n4,n7:longint;
  i:longint;
begin
  read(s);
  n4:=0;
  n7:=0;
  for i:=1 to length(s) do
    begin
      if s[i]='4' then inc(n4);
      if s[i]='7' then inc(n7);
    end;
  if n4+n7=0 then begin writeln(-1); halt; end;
  if n4>=n7 then writeln(4)
  else writeln(7);
end.