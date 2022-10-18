uses math;
var
  s:ansistring;
  i,j,h:longint;
begin
  read(s);
  for i:=1 to length(s)-6 do
    begin
      h:=1;
      for j:=i+1 to i+6 do
        if s[j]<>s[j-1] then begin h:=0; break; end;
      if h=1 then begin writeln('YES'); halt; end;
    end;
  writeln('NO');
end.