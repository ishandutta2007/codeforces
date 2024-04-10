uses math;
var
  s1,s2:ansistring;
  i:longint;
begin
  readln(s1);
  readln(s2);
  for i:=1 to length(s1) do
    begin
      if (ord(s1[i])>=97) and (ord(s1[i])<=122) then s1[i]:=chr(ord(s1[i])-32);
      if (ord(s2[i])>=97) and (ord(s2[i])<=122) then s2[i]:=chr(ord(s2[i])-32);
    end;

  for i:=1 to length(s1) do
    begin
      if ord(s1[i])>ord(s2[i]) then begin writeln(1); halt; end;
      if ord(s1[i])<ord(s2[i]) then begin writeln(-1); halt; end;
    end;
  writeln(0);
end.