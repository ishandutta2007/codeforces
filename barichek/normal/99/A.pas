uses math;
var
  s:ansistring;
  i:longint;
begin
  read(s);
  for i:=1 to length(s) do
    if s[i]='.' then break;

  if s[i-1]='9' then begin writeln('GOTO Vasilisa.'); halt; end;
  if ord(s[i+1])-48>=5 then
    s[i-1]:=chr(ord(s[i-1])+1);
  writeln(copy(s,1,i-1));
end.