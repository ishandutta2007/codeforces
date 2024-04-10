uses math;
var
  a:longint;
  i,j,h:longint;
begin
  h:=1;
  for i:=1 to 5 do
    begin
      for j:=1 to 5 do
        begin
          read(a);
          if a=1 then begin h:=0; break; end;
        end;
      if h=0 then break;
    end;
  writeln(abs(i-3)+abs(j-3));
end.