uses math;
var
  s,ans:ansistring;
  i,h:longint;
begin
  read(s);

  h:=0;
  for i:=1 to length(s) do
    begin
      if h=1 then
        begin
          if s[i]='.' then ans:=ans+'1';
          if s[i]='-' then ans:=ans+'2';
          h:=0;
          continue;
        end;
      if s[i]='.' then ans:=ans+'0';
      if s[i]='-' then h:=1
      else h:=0;
    end;
  writeln(ans);
end.