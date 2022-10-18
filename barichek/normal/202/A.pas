uses math;
var
  s:string;
  maxi:longint;
  i:longint;
begin
  read(s);
  maxi:=ord(s[1]);
  for i:=2 to length(s) do
    maxi:=max(maxi,ord(s[i]));
  for i:=1 to length(s) do
    if maxi=ord(s[i]) then write(s[i]);
end.