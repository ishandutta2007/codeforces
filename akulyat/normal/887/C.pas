Program Rubik;
var  gl,itog:boolean;
     k,t:array[1..24]of longint;
     i:longint; 



begin
gl:=false;


for i:=1 to 24 do
  read(k[i]);

for i:=1 to 24 do
  t[i]:=k[i];  
t[8]:=k[12];
t[6]:=k[10];
t[4]:=k[8];
t[2]:=k[6];  
t[21]:=k[4];
t[23]:=k[2];
t[12]:=k[21];
t[10]:=k[23];
itog:=true;
for i:=0 to 5 do
  if (t[i*4+1]<>t[i*4+2]) or (t[i*4+1]<>t[i*4+3]) or (t[i*4+1]<>t[i*4+4]) or (t[i*4+2]<>t[i*4+3]) or (t[i*4+2]<>t[i*4+4]) or (t[i*4+3]<>t[i*4+4])  then
    itog:=false;
if itog=true then gl:=true;
  
for i:=1 to 24 do
  t[i]:=k[i];  
t[8]:=k[4];
t[6]:=k[2];
t[4]:=k[21];
t[2]:=k[23];  
t[21]:=k[12];
t[23]:=k[10];
t[12]:=k[8];
t[10]:=k[6];
itog:=true;
for i:=0 to 5 do
  if (t[i*4+1]<>t[i*4+2]) or (t[i*4+1]<>t[i*4+3]) or (t[i*4+1]<>t[i*4+4]) or (t[i*4+2]<>t[i*4+3]) or (t[i*4+2]<>t[i*4+4]) or (t[i*4+3]<>t[i*4+4])  then
    itog:=false;
if itog=true then gl:=true;


for i:=1 to 24 do
  t[i]:=k[i];  
t[13]:=k[21];
t[14]:=k[22];
t[5]:=k[13];
t[6]:=k[14];  
t[17]:=k[5];
t[18]:=k[6];
t[21]:=k[17];
t[22]:=k[18];
itog:=true;
for i:=0 to 5 do
  if (t[i*4+1]<>t[i*4+2]) or (t[i*4+1]<>t[i*4+3]) or (t[i*4+1]<>t[i*4+4]) or (t[i*4+2]<>t[i*4+3]) or (t[i*4+2]<>t[i*4+4]) or (t[i*4+3]<>t[i*4+4])  then
    itog:=false;
if itog=true then gl:=true;
    
    
    
for i:=1 to 24 do
  t[i]:=k[i];  
t[13]:=k[5];
t[14]:=k[6];
t[5]:=k[17];
t[6]:=k[18];  
t[17]:=k[21];
t[18]:=k[22];
t[21]:=k[13];
t[22]:=k[14];
itog:=true;
for i:=0 to 5 do
  if (t[i*4+1]<>t[i*4+2]) or (t[i*4+1]<>t[i*4+3]) or (t[i*4+1]<>t[i*4+4]) or (t[i*4+2]<>t[i*4+3]) or (t[i*4+2]<>t[i*4+4]) or (t[i*4+3]<>t[i*4+4])  then
    itog:=false;
if itog=true then gl:=true;


for i:=1 to 24 do
  t[i]:=k[i];  
t[14]:=k[4];
t[16]:=k[3];
t[9]:=k[14];
t[10]:=k[16];  
t[19]:=k[9];
t[17]:=k[10];
t[4]:=k[19];
t[3]:=k[17];
itog:=true;
for i:=0 to 5 do
  if (t[i*4+1]<>t[i*4+2]) or (t[i*4+1]<>t[i*4+3]) or (t[i*4+1]<>t[i*4+4]) or (t[i*4+2]<>t[i*4+3]) or (t[i*4+2]<>t[i*4+4]) or (t[i*4+3]<>t[i*4+4])  then
    itog:=false;
if itog=true then gl:=true;

for i:=1 to 24 do
  t[i]:=k[i];  
t[14]:=k[9];
t[16]:=k[10];
t[9]:=k[19];
t[10]:=k[17];  
t[19]:=k[4];
t[17]:=k[3];
t[4]:=k[14];
t[3]:=k[16];
itog:=true;
for i:=0 to 5 do
  if (t[i*4+1]<>t[i*4+2]) or (t[i*4+1]<>t[i*4+3]) or (t[i*4+1]<>t[i*4+4]) or (t[i*4+2]<>t[i*4+3]) or (t[i*4+2]<>t[i*4+4]) or (t[i*4+3]<>t[i*4+4])  then
    itog:=false;
if itog=true then gl:=true;


if gl=true then writeln('YES') else
   writeln('NO');

end.